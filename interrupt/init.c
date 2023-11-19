#include <xc.h>
#include "priorities.h"

void interrupt_uart1rx_init(){
    /*
     * Prepares UART1 with RX interrupt.
     * 
     * This interupt signals reception of GNSS module message, usually in UBX
     * format, given that the module is properly so configured, and a new char
     * has to be received.
     */
    IFS0bits.U1RXIF = 0;
    IPC6bits.U1IP = INTERRUPT_UART1RX_PRIORITY;
    IPC6bits.U1IS = INTERRUPT_UART1RX_SUBPRIORITY;
}

void interrupt_uart1rx_enable(){
    IEC0bits.U1RXIE = 1;
}

void interrupt_uart1rx_clear(){
    IFS0bits.U1RXIF = 0;
}

void interrupt_uart1rx_disable(){
    IEC0bits.U1RXIE = 0;
}


void interrupt_int1_init(){
    /*
     * Prepares INT1 interrupt
     * 
     * This interrupt receives the 1PPS signal from GNSS7 module for seconds-
     * turnover. This is always the highest priority.
     */
    IPC1bits.INT1IP = 7;
    IPC1bits.INT1IS = 3;
    IFS0bits.INT1IF = 0;
    INTCONbits.INT1EP = 0; // falling edge
}

void interrupt_int1_enable(){
    IEC0bits.INT1IE = 1;
}

void interrupt_int1_clear(){
    IFS0bits.INT1IF = 0;
}

void interrupt_int1_disable(){
    IEC0bits.INT1IE = 0;
}



void interrupt_init(){
    INTCONSET = _INTCON_MVEC_MASK;
    interrupt_int1_init();
    interrupt_uart1rx_init();
    __builtin_enable_interrupts();
}