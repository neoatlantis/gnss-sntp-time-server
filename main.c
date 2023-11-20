/*
 * File:   main.c
 * Author: standard
 *
 * Created on 2023年10月18日, 下午10:27
 */

#include "config_bits.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <xc.h>


#include "coretime.h"
#include "uart.h"
#include "spi.h"
#include "interrupt/init.h"

#include "gnss/ubx_message_parser.h"
#include "gnss/ubx_message_process.h"
#include "system_config.h"
#include "customized_params.h"
#include "sntp/sntp.h"

#include "time_broadcaster.h"




void main(void) {
    
    //coretime_init();
    interrupt_init();
    
    spi2_enable();
    uart1_enable();
    uart2_enable();
    
    interrupt_uart1rx_enable();
    
    printf("\033[2J----\n\r");
    printf("NeoAtlantis GNSS Time Server\n\r");
    printf("-- Project YueChengLing\n\r");
    
    time_broadcaster_init();
    
    
    while(1){
        WDTCONbits.WDTCLR = 1;
        
        ubx_message_process_on_tick();
        
        /*
        NICUDPPacket udpp = w5500_udp_socket_read(&nic, 0);
        if(udpp.bufferSize > 0){
            printf(
                "Read %d bytes from %d.%d.%d.%d:%d\n\r", udpp.bufferSize,
                    udpp.src_addr.octet0,
                    udpp.src_addr.octet1,
                    udpp.src_addr.octet2,
                    udpp.src_addr.octet3,
                    (udpp.src_port.octetH << 8 | udpp.src_port.octetL)
            );
            
            // modify udpp for reply, test purpose.
            memcpy(udpp.dst_addr.octet, udpp.src_addr.octet, 4);
            memcpy(udpp.dst_port.octet, udpp.src_port.octet, 2);
            w5500_udp_socket_send(nic, 0, &udpp);
            
            udpp.bufferSize = 0;
        }*/
    }
    
    return;
}
