#include "unity.h" // Single Unity Test Framework include
#include <stdio.h>

#include "c_period_callbacks.h"

// Mock the UART2 C header API
#include "Mockc_uart.h"
#include "Mockc_led_display.h"

void setUp(void) {
}
void tearDown(void) {
}

void test_C_period_init(void) {
//  TEST_ASSERT_TRUE(C_period_init());


    uart_init_ExpectAndReturn(2,9600,0,0,true);
    uart_init_IgnoreArg_rxQSize();
    uart_init_IgnoreArg_txQSize();
    c_led_display_init_ExpectAnyArgsAndReturn(true);
    c_led_display_clear_Expect();

    C_period_init();
}


void test_C_period_10Hz(void) {
    uart_getchar_ExpectAndReturn(2,0,0,true);
    uart_getchar_IgnoreArg_byte();
    c_led_display_set_number_ExpectAnyArgs();
    C_period_10Hz(0);
}
