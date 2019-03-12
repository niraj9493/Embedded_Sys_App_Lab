/*
 * c_light_sensor.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Niraj93
 */

#ifndef C_LIGHT_SENSOR_H_
#define C_LIGHT_SENSOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

bool c_lightsensor_init(void); ///< Initializes this device, @returns true if successful

uint16_t c_getRawValue(void);       ///< @returns light sensor reading
uint8_t  c_getPercentValue(void);


#ifdef __cplusplus
}
#endif

#endif /* C_LIGHT_SENSOR_H_ */
