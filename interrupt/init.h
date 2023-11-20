#ifndef _INTERRUPT_INIT_H    /* Guard against multiple inclusion */
#define _INTERRUPT_INIT_H

#include <stdbool.h>

void interrupt_uart1rx_init();
void interrupt_uart1rx_enable();
void interrupt_uart1rx_clear();
void interrupt_uart1rx_disable();

void interrupt_int1_init();
void interrupt_int1_enable();
void interrupt_int1_clear();
void interrupt_int1_disable();
bool interrupt_int1_flag();

void interrupt_init();


#endif