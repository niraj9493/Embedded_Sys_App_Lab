/**
 * @file
 *
 * The purpose of this "C" callbacks is to provide the code to be able
 * to call pure C functions and unit-test it in C test framework
 */
#include <stdint.h>
#include <stdbool.h>
#include "c_uart.h"
#include "c_led_display.h"

#define LAB1 0
#define LAB2 1

#if LAB1
#include "gpio.hpp"
#include "eint.h"

GPIO SWIT(P2_7);        //Pin connected to external switch
GPIO CommPin(P2_6);     //Communication Pin between two controllers.
uint8_t prev = 0;       //Variable for storing periodic 'count' variable when interrupt is generated.
SemaphoreHandle_t Signal = 0;

#endif

#if LAB1

//Intr Routine
void intr()
{
    //    printf("Pressed\n");
    xSemaphoreGiveFromISR(Signal, 0);
}

#endif

bool C_period_init(void) {
#if LAB1
    SWIT.setAsInput();
    CommPin.setAsOutput();
    Signal = xSemaphoreCreateBinary();
    eint3_enable_port2(7, eint_rising_edge, intr);
#endif

#if LAB2
//    uart2_init(9600,32,32);
    uart_init(uart2,9600,32,32);
    c_led_display_init();
    c_led_display_clear();
#endif

    return true;
}
bool C_period_reg_tlm(void) {
    return true;
}

void C_period_1Hz(uint32_t count) {
    (void) count;

#if LAB1

#else

#endif

}

void C_period_10Hz(uint32_t count) {
    (void) count;
#if LAB1
    if (xSemaphoreTake(Signal, 0))
    {
        CommPin.setHigh();
        prev = count;
    }
    if (count == (prev + 5))
    {
        CommPin.setLow();
    }

#elif LAB2

    char byte = 0;
    if(uart_getchar(uart2,&byte, 0))
    {
        c_led_display_set_number(byte);
    }
#else

    //LE.toggle(2);

#endif
}

void C_period_100Hz(uint32_t count) {
    (void) count;
}

void C_period_1000Hz(uint32_t count) {
    (void) count;
}
