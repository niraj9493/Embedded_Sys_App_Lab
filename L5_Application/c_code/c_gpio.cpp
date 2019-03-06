/*
 * c_gpio.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: gaura
 */


#include "c_gpio.h"
#include "io.hpp"
#include "printf_lib.h"


bool readSwitch(int pinNum)
{
    //printf("read switch\n");
    return SW.getSwitch(pinNum);
}


