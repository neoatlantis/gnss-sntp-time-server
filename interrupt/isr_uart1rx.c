#include <xc.h>
#include <sys/attribs.h>
#include <stdint.h>
#include <stdio.h>
#include "priorities.h"
#include "init.h"

#include "../gnss/ubx_message_parser.h"
#include "../gnss/ubx_message_process.h"

void __ISR(_UART_1_VECTOR, INTERRUPT_UART1RX_IRQ) isr_uart1rx(){
    UBX_PARSER_STATE* parser_ret;
    while(U1STAbits.URXDA){
        uint8_t c = U1RXREG;
        parser_ret = ubx_message_parser_recv_char(c);
        if(NULL != parser_ret){
            // get new UBX message
            ubx_message_process_on_new_message(parser_ret);
        }
    }
    if (U1STAbits.OERR) U1STAbits.OERR = 0;
    if (U1STAbits.PERR) U1STAbits.PERR = 0;
    if (U1STAbits.FERR) U1STAbits.FERR = 0;
    interrupt_uart1rx_clear();
}