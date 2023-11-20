#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "../nic/nic.h"
#include "registers.h"
#include "spi.h"
#include "udp_socket.h"

uint8_t W5500_COMMON_BUFFER[2048];

void w5500_send_socket_command(NIC* nic, uint8_t socket_n, uint8_t command){
    // Send command to socket
    w5500_spi_exchange_buffer(
        nic, &command,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_CR
    );
}

uint8_t w5500_get_socket_status(NIC* nic, uint8_t socket_n){
    uint8_t ret;
    w5500_spi_exchange_buffer(
        nic, &ret,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),    
        ADDR_SOCKET_SR
    );
    return ret;
}

void w5500_open_udp_socket(NIC* nic, uint8_t socket_n, uint16_t port){
    
    W5500_uint16_t PORTR;
    PORTR.H = port >> 8;
    PORTR.L = port & 0xFF;
    
    // set socket mode
    
    REG_SOCKET_MR MR = {
        .PROTOCOL = 0b0010, // udp
        .UCASTB = 0,
        .BCASTB = 1
    };
    w5500_spi_exchange_buffer(
        nic, &MR.value,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_MR
    );
    
    // set up port
    
    w5500_spi_exchange_buffer(
        nic, PORTR.value,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_PORT
    );
    
    // open socket
    w5500_send_socket_command(nic, socket_n, W5500_SOCK_CMD_OPEN);
    while(W5500_SOCK_UDP != w5500_get_socket_status(nic, socket_n));
}


bool w5500_udp_socket_recv(NIC* nic, uint8_t socket_n, NICUDPPacket *ret){
    ret->bufferSize = 0;
    
    uint16_t bytes_read = 0;
    REG_SOCKET_RX_RSR RSR;
    uint16_t rxbuf_usage;
    w5500_spi_exchange_buffer(
        nic, RSR.value,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
        ADDR_SOCKET_RX_RSR
    );
    rxbuf_usage = (RSR.H << 8) | RSR.L;
    
    if(rxbuf_usage > 8){ // rxbuf header: 4 bytes IP, 2 bytes Port, 2 bytes Len
        REG_SOCKET_RX_RD rx_read_start_buf;
        uint16_t rx_read_start;
        w5500_spi_exchange_buffer(
            nic, rx_read_start_buf.value,
            W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
            ADDR_SOCKET_RX_RD
        );
        rx_read_start = (rx_read_start_buf.H << 8) | rx_read_start_buf.L;
        
        if(rxbuf_usage > NIC_UDP_MAX_BUFFER){
            bytes_read = NIC_UDP_MAX_BUFFER;
        } else {
            bytes_read = rxbuf_usage;
        }
        
        w5500_spi_exchange_buffer(
            nic, W5500_COMMON_BUFFER,
            W5500_CTRL_BYTE_RD_SOCKET_RX(socket_n),
            rx_read_start, bytes_read
        );
        
        uint16_t udp_length = (W5500_COMMON_BUFFER[6]) << 8 | W5500_COMMON_BUFFER[7];
        memcpy(ret->src_addr.octet, W5500_COMMON_BUFFER, 4);
        memcpy(ret->src_port.octet, W5500_COMMON_BUFFER+4, 2);
        memcpy(ret->dst_addr.octet, nic->ip_device.octet, 4);
        //memcpy(ret.dst_port.octet, nic->ip) // TODO
        ret->bufferSize = bytes_read - 8;
        memcpy(ret->buffer, W5500_COMMON_BUFFER+8, ret->bufferSize);
        
        
        if(udp_length != ret->bufferSize){
            ret->bufferSize = 0; // error! // TODO
        }
        
        
        if(bytes_read > 0){
            // increase RD pointer by 2 + packet_size
            rx_read_start += bytes_read;
            rx_read_start_buf.H = rx_read_start >> 8;
            rx_read_start_buf.L = rx_read_start & 0xFF;
            w5500_spi_exchange_buffer(
                nic, rx_read_start_buf.value,
                W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
                ADDR_SOCKET_RX_RD
            );
        }
    }
    
    // Check interrupt register of socket
    /*REG_SOCKET_IR IR;
    w5500_spi_exchange_buffer(
        nic, &IR.value,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
        ADDR_SOCKET_IR
    );
    if(bytes_read > 0) printf("Debug: IR=%x\n\r", IR.value);
    // Clear interrupts
    IR.value = 0xFF;
    w5500_spi_exchange_buffer(
        nic, &IR.value,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_IR
    );*/
    
    // sets out another RECV command
    w5500_send_socket_command(nic, socket_n, W5500_SOCK_CMD_RECV);
    
    return true;
}

bool w5500_udp_socket_send(NIC* nic, uint8_t socket_n, NICUDPPacket* udpp){
    // Preserve send WR pointer
    REG_SOCKET_TX_WR TX_WR;
    w5500_spi_exchange_buffer(
        nic, TX_WR.value,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
        ADDR_SOCKET_TX_WR
    );
    uint16_t txbuf_offset = (TX_WR.H << 8) | (TX_WR.L);
    uint16_t bytes_written = w5500_udp_socket_fill_txbuf(nic, socket_n, udpp, txbuf_offset);

    if(bytes_written != udpp->bufferSize){
        return false;
    }
    
    // update TX_WR
    txbuf_offset += udpp->bufferSize;
    TX_WR.H = txbuf_offset >> 8;
    TX_WR.L = txbuf_offset & 0xFF;
    w5500_spi_exchange_buffer(
        nic, TX_WR.value,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_TX_WR
    );
    
    // command send
    w5500_send_socket_command(nic, socket_n, W5500_SOCK_CMD_SEND);
    return true;
}

uint16_t w5500_udp_socket_fill_txbuf(
    NIC* nic,
    uint8_t socket_n,
    NICUDPPacket *udpp,
    uint8_t txbuf_offset
){
    // Fill send buffer on w5500, but NOT INCREASING TX POINTER!
    
    REG_SOCKET_TX_FSR FSR;
    w5500_spi_exchange_buffer(
        nic, FSR.value,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
        ADDR_SOCKET_TX_FSR
    );
    uint16_t txbuf_free = (FSR.H << 8) | FSR.L; // free bytes in TX buffer
    
    if(txbuf_free < udpp->bufferSize) return 0;
    
    REG_SOCKET_DIPR DIPR;
    REG_SOCKET_DPORT DPORT;
    
    memcpy(DIPR.octet, udpp->dst_addr.octet, 4);
    memcpy(DPORT.octet, udpp->dst_port.octet, 2);
    w5500_spi_exchange_buffer(
        nic, DIPR.octet,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_DIPR
    );
    w5500_spi_exchange_buffer(
        nic, DPORT.octet,
        W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
        ADDR_SOCKET_DPORT
    );
    
    // Fill send buffer
    
    w5500_spi_exchange_buffer(
        nic, udpp->buffer,
        W5500_CTRL_BYTE_WR_SOCKET_TX(socket_n),
        txbuf_offset, udpp->bufferSize
    );
    
    return udpp->bufferSize;
}

uint16_t w5500_udp_socket_send_deferred_ready(NIC* nic, uint8_t socket_n, NICUDPPacket* udpp, bool override){
    // Preserve send WR pointer
    REG_SOCKET_TX_WR TX_WR;
    w5500_spi_exchange_buffer(
        nic, TX_WR.value,
        W5500_CTRL_BYTE_RD_SOCKET_REG(socket_n),
        ADDR_SOCKET_TX_WR
    );
    uint16_t txbuf_offset = (TX_WR.H << 8) | (TX_WR.L);
    uint16_t bytes_written = w5500_udp_socket_fill_txbuf(nic, socket_n, udpp, txbuf_offset);

    if(bytes_written != udpp->bufferSize){
        return 0;
    }
    
    if(!override){
        // update TX_WR
        txbuf_offset += udpp->bufferSize;
        TX_WR.H = txbuf_offset >> 8;
        TX_WR.L = txbuf_offset & 0xFF;
        w5500_spi_exchange_buffer(
            nic, TX_WR.value,
            W5500_CTRL_BYTE_WR_SOCKET_REG(socket_n),
            ADDR_SOCKET_TX_WR
        );
    }
    return bytes_written;
}

void w5500_udp_socket_send_deferred_go(NIC* nic, uint8_t socket_n){
    w5500_send_socket_command(nic, socket_n, W5500_SOCK_CMD_SEND);
}