/*
 * c_light_sensor.cpp
 *
 *  Created on: Mar 9, 2019
 *      Author: Niraj93
 */

#include "c_light_sensor.h"
#include "io.hpp" // error: expected '{' before '<' token
#include "light_sensor.hpp"

//Global Light Sensor pointer
Light_Sensor *light_sen = NULL;

bool c_lightsensor_init()
{
    light_sen = &Light_Sensor::getInstance();
    return light_sen->init();
}

uint16_t c_getRawValue()
{
    return light_sen->getRawValue();
}
uint8_t c_getPercentValue()
{
    return light_sen->getPercentValue();
}
