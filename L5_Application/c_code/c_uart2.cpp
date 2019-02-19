#include "c_uart2.h"
#include "uart2.hpp"

// Assuming UART2 is already initialized
// You may want to also add uart2_init() in C

//Global Uart2 pointer
Uart2 *u2 = NULL;

bool uart2_init(int baudRate,int rxQSize,int txQSize)
{
    u2 = &Uart2::getInstance();
    return u2->init(baudRate,rxQSize,txQSize);
}

bool uart2_getchar(char *byte, uint32_t timeout_ms)
{
   return u2->getChar(byte, timeout_ms);
}

bool uart2_putchar(char out, uint32_t timeout_ms)
{
   return u2->putChar(out,timeout_ms);
}
