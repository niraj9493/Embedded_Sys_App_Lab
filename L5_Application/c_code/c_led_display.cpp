/*
 * c_led_display.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: Niraj93
 */
#include "c_led_display.h"
#include "LED_Display.hpp"

LED_Display *led = NULL;

bool c_led_display_init(void)
{
    led = &LED_Display::getInstance();
    return led->init();
}

void c_led_display_clear(void)
{
    led->clear();
}

void c_led_display_set_number(char num)
{
    led->setNumber(num);
}

