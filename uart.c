#include "uart.h"
#include <xc.h>
#include <stdio.h>

void uart1_enable(){
    U1BRG = UART1_BRG_VAL;
    U1MODEbits.UEN = 0b00;
    U1MODEbits.ON = 1;
    U1STAbits.URXEN = 1;
}

void uart2_enable(){
    U2BRG = UART2_BRG_VAL;
    U2MODEbits.UEN = 0b00;
    U2MODEbits.ON = 1;
    U2STAbits.UTXEN = 1;
}

void putch(char ch){
    while(U1STAbits.UTXBF);             // Wait until buffer is empty
    U1TXREG = ch;                       // Transmit character
}