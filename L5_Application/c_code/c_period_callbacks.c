/**
 * @file
 *
 * The purpose of this "C" callbacks is to provide the code to be able
 * to call pure C functions and unit-test it in C test framework
 */

#include "c_period_callbacks.h"
#include "c_uart.h"
#include "c_led_display.h"
#include "c_gpio.h"
#include "can.h" //LAB3 & LAB4
#include "c_light_sensor.h" //LAB4
#include <string.h> //LAB4
#include <generated_can.h> //LAB4

bool dbc_app_send_can_msg(uint32_t mid, uint8_t dlc, uint8_t bytes[8])
{
    can_msg_t can_msg = { 0 };
    can_msg.msg_id                = mid;
    can_msg.frame_fields.data_len = dlc;
    memcpy(can_msg.data.bytes, bytes, dlc);

    return CAN_tx(can1, &can_msg, 0);
}


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
    uart_init(uart2,9600,32,32);
    c_led_display_init();
    c_led_display_clear();
#endif

#if LAB3TX || LAB3RX
    c_led_display_init();
    c_led_display_clear();
    CAN_init(can1,100,100,100,NULL,NULL);
    CAN_reset_bus(can1);
    CAN_bypass_filter_accept_all_msgs();
    CAN_reset_bus(can1);

#endif

    c_lightsensor_init();
    CAN_init(can1,100,100,100,NULL,NULL);
    CAN_bypass_filter_accept_all_msgs();
    CAN_reset_bus(can1);

    return true;
}

bool C_period_reg_tlm(void) {
    return true;
}

void C_period_1Hz(uint32_t count) {
    (void) count;

#if LAB1

#elif LAB2

#elif LAB3TX || LAB3RX

        CAN_reset_bus(can1);
        CAN_bypass_filter_accept_all_msgs();
        CAN_reset_bus(can1);
#endif


        CAN_bypass_filter_accept_all_msgs();
        CAN_reset_bus(can1);
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

#elif LAB3TX

    can_msg_t tx_msg;
    tx_msg.msg_id = 0x100;
    tx_msg.frame_fields.is_29bit = 1; //1 if the 11-bit ID
    tx_msg.frame_fields.data_len = 8;
    tx_msg.data.qword = 0x1122334455667788;
    if(readSwitch(2))
    {
       tx_msg.data.bytes[0] = 0xAA;
       if(CAN_tx(can1, &tx_msg, 0))
       {
           printf("switch pressed");
       }
    }
    else
    {
        tx_msg.data.bytes[0] = 0x00;
        if(CAN_tx(can1, &tx_msg, 0))
        {
            printf("Switch not pressed");
        }
    }


#endif

#if LAB3RX

    can_msg_t rx_msg;
    if(CAN_rx(can1,&rx_msg,1))
    {
        printf("->\n");
        if(rx_msg.data.bytes[0] == 0xAA)
        {
            c_led_display_set_number(1);
        }
        else
        {
            c_led_display_set_number(0);
        }
    }

#else

    //LE.toggle(2);
    SensorStructure_t obj;
    obj.MY_SENSOR_unsigned1 = c_getPercentValue();
    dbc_encode_and_send_SensorStructure(&obj);


#endif
}

void C_period_100Hz(uint32_t count) {
    (void) count;
}

void C_period_1000Hz(uint32_t count) {
    (void) count;
}
