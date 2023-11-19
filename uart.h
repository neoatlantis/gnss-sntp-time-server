/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _UART_H    /* Guard against multiple inclusion */
#define _UART_H

#include "system_config.h"
#define UART1_BAUDRATE 38400
#define UART1_BRG_VAL  (PBCLK / 16 / UART1_BAUDRATE - 1)

#define UART2_BAUDRATE 115200
#define UART2_BRG_VAL  (PBCLK / 16 / UART2_BAUDRATE - 1)

void putch(char);
void uart1_enable();
void uart2_enable();

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
