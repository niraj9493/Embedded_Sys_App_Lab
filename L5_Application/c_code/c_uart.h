/*
 * c_uart.h
 *
 *  Created on: Feb 19, 2019
 *      Author: Niraj93
 */

#ifndef C_UART_H_
#define C_UART_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    uart2 = 2,
    uart3
}uart;



bool uart_init(uart u,int baudRate,int rxQSize,int txQSize);

bool uart_getchar(uart u,char *byte, uint32_t timeout_ms);

bool uart_putchar(uart u,char out, uint32_t timeout_ms);


#ifdef __cplusplus
}
#endif

#endif /* C_UART_H_ */
