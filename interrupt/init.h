#ifndef _INTERRUPT_INIT_H    /* Guard against multiple inclusion */
#define _INTERRUPT_INIT_H

void interrupt_uart1rx_init();
void interrupt_uart1rx_enable();
void interrupt_uart1rx_clear();
void interrupt_uart1rx_disable();



void interrupt_init();


#endif