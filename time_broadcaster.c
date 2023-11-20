/*
 * Broadcast time over w5500 Ethernet NIC.
 * 
 * This module does following tasks:
 *   1. setup w5500 for generic operation
 *   2. receives notification from UART on UBX timestamps.
 *   3. prefill the w5500 send buffer with timestamp corresponding for next PPS
 *      event. During this period, external interrupt on PPS is disabled. 
 *      This is to check whether a PPS occurred during filling the buffer, which
 *      will render the packet useless.
 *   4. On PPS event, instruct w5500 to send the packet ASAP.
 */

#include <string.h>
#include <time.h>
#include <stdio.h>
#include "nic/nic.h"
#include "w5500/new.h"
#include "w5500/udp_socket.h"
#include "customized_params.h"
#include "sntp/sntp.h"
#include "time_broadcaster.h"
#include "spi.h"
#include "interrupt/init.h"

NIC nic;
NICUDPPacket udpp;
SNTP_MESSAGE sntpmsg;

bool NEXT_TICK_UPDATED_SUCCESSFUL;
bool FIRST_UPDATE_IN_THIS_PERIOD;

void w5500_select(){
    spi2_set_mode_8();
    spi2_slot2_select();
}

void w5500_deselect(){
    spi2_deselect_all();
}

void time_broadcaster_init(){
    nic.id = 0;
    memcpy(&nic.mac.octet,       &(uint8_t[6]){ 0x02, 0x20, 0x07, 'J', 'V', 0x22 }, 6);
    memcpy(&nic.ip_device.octet, &(uint8_t[4]){ LOCAL_IP }, 4);
    memcpy(&nic.ip_netmask.octet,&(uint8_t[4]){ NETMASK }, 4);
    
    nic.driver.spi_select = w5500_select;
    nic.driver.spi_deselect = w5500_deselect;
    nic.driver.spi_exchange_register = spi2_exchange_buffer;
    
    w5500_new(&nic);
    
    printf("Initialize W5500 at slot 1...\n\r");
    nic.init(&nic);
    
    printf("Opening UDP port at slot 1...\n\r");
    w5500_open_udp_socket(&nic, 0, 123);
    
    printf("Preparing template SNTP broadcast message.\n\r");
    sntp_message_new_server_broadcast(&sntpmsg);
    memcpy(&udpp.dst_addr.octet, &(uint8_t[4]){ BROADCAST_IP }, 4);
    udpp.dst_port.octetH = 0;
    udpp.dst_port.octetL = 123;
    
    printf("Init done.\n\r");
}




void time_broadcaster_on_time_update(struct tm* update){
    interrupt_int1_disable();
    
    uint32_t next_tick_seconds = (uint32_t) mktime(update);
    SNTP_DWORD_FILL(sntpmsg.transmit_timestamp.seconds, next_tick_seconds);
    SNTP_DWORD_FILL(sntpmsg.transmit_timestamp.fraction_seconds, 0);
    
    memcpy(udpp.buffer, sntpmsg.chars, sizeof(sntpmsg.chars));
    udpp.bufferSize = sizeof(sntpmsg.chars);
    
    uint16_t bytes_written = w5500_udp_socket_send_deferred_ready(
        &nic, 0, &udpp, !FIRST_UPDATE_IN_THIS_PERIOD);
    
    if(bytes_written){
        if(!interrupt_int1_flag()){
            NEXT_TICK_UPDATED_SUCCESSFUL = true;
            FIRST_UPDATE_IN_THIS_PERIOD = false;
        } else {
            NEXT_TICK_UPDATED_SUCCESSFUL = false;
            interrupt_int1_clear();
        }
    }
    
    interrupt_int1_enable();
    printf("Next tick @ %d\n\r", next_tick_seconds);
}

void time_broadcaster_on_1pps(){
    if(NEXT_TICK_UPDATED_SUCCESSFUL){
        w5500_udp_socket_send_deferred_go(&nic, 0);
    }
    
    FIRST_UPDATE_IN_THIS_PERIOD = true;
    NEXT_TICK_UPDATED_SUCCESSFUL = false;
}