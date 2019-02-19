/*
 * c_uart.cpp
 *
 *  Created on: Feb 19, 2019
 *      Author: Niraj93
 */

#include "c_uart.h"
#include "uart2.hpp"
#include "uart3.hpp"


//Global Uart pointers
Uart2 *u2 = NULL;
Uart3 *u3 = NULL;

bool uart_init(uart u,int baudRate,int rxQSize,int txQSize)
{
    switch(u)
    {
        case uart2: u2 = &Uart2::getInstance();
                    return u2->init(baudRate,rxQSize,txQSize);
        case uart3: u3 = &Uart3::getInstance();
                    return u3->init(baudRate,rxQSize,txQSize);
    }
}


bool uart_getchar(uart u,char *byte, uint32_t timeout_ms)
{
    switch(u)
    {
        case uart2: return u2->getChar(byte, timeout_ms);

        case uart3: return u3->getChar(byte, timeout_ms);
    }
}



bool uart_putchar(uart u,char out, uint32_t timeout_ms)
{
    switch(u)
    {
        case uart2: return u2->putChar(out,timeout_ms);

        case uart3: return u3->putChar(out,timeout_ms);
    }
}
