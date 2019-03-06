#include "unity.h" // Single Unity Test Framework include
#include <stdio.h>

#include "c_period_callbacks.h"

// Mock the UART2 C header API
#include "Mockc_uart.h"
#include "Mockc_led_display.h"
#include "Mockcan.h"
#include "Mockc_gpio.h"

#define LAB3 1      //<- CAN Communication Between two boards


void setUp(void) {
}
void tearDown(void) {
}

void test_C_period_init(void) {
//  TEST_ASSERT_TRUE(C_period_init());

#if LAB2
    uart_init_ExpectAndReturn(2,9600,0,0,true);
    uart_init_IgnoreArg_rxQSize();
    uart_init_IgnoreArg_txQSize();
    c_led_display_init_ExpectAnyArgsAndReturn(true);
    c_led_display_clear_Expect();
#endif

#if LAB3TX || LAB3RX
    c_led_display_init_ExpectAnyArgsAndReturn(true);
    c_led_display_clear_Expect();
    CAN_init_ExpectAndReturn(0,100,100,100,0,0,true);
    CAN_reset_bus_Expect(0); //can1 = 0
    CAN_bypass_filter_accept_all_msgs_Expect();
    CAN_reset_bus_Expect(0); //can1 = 0


#endif
    C_period_init();
}


void test_C_period_10Hz(void) {

#if LAB2
    uart_getchar_ExpectAndReturn(2,0,0,true);
    uart_getchar_IgnoreArg_byte();
    c_led_display_set_number_ExpectAnyArgs();
#endif

#if LAB3TX
    readSwitch_ExpectAndReturn(2,true);
    CAN_tx_ExpectAndReturn(0,0,0,true);
    CAN_tx_IgnoreArg_msg();

    C_period_10Hz(0);

    readSwitch_ExpectAndReturn(2,false);
    CAN_tx_ExpectAndReturn(0,0,0,true);
    CAN_tx_IgnoreArg_msg();

    C_period_10Hz(0);
#endif

#if LAB3RX

    CAN_rx_ExpectAndReturn(0,0,0,true);
    CAN_rx_IgnoreArg_msg();
    c_led_display_set_number_ExpectAnyArgs();
    C_period_10Hz(0);

#endif

}

void test_C_period_1Hz(void)
{
#if LAB3TX || LAB3RX
    CAN_reset_bus_Expect(0); //can1 = 0
    CAN_bypass_filter_accept_all_msgs_Expect();
    CAN_reset_bus_Expect(0); //can1 = 0
#endif

    C_period_1Hz(0);

}


