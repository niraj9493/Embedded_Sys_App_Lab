/*
 * c_gpio.h
 *
 *  Created on: Mar 5, 2019
 *      Author: gaura
 */


#ifndef C_GPIO_H_
#define C_GPIO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


bool readSwitch(int pinNum);


#ifdef __cplusplus
}
#endif

#endif /* C_GPIO_H_ */
