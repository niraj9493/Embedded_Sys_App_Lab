#include "unity.h" // Single Unity Test Framework include
#include <stdio.h>

#include "c_period_callbacks.h"

// Mock the UART2 C header API
#include "Mockc_uart2.h"
#include "Mockc_led_display.h"

void setUp(void) {
}
void tearDown(void) {
}

void test_C_period_init(void) {
  TEST_ASSERT_TRUE(C_period_init());
}


void test_C_period_1Hz(void) {
    uart2_getchar_ExpectAndReturn(NULL, 0, false);
    uart2_getchar_IgnoreArg_byte();
    c_led_display_set_number_ExpectAndReturn(NULL,false);
    c_led_display_set_number_IgnoreArg_num();
    C_period_1Hz(0);
}
