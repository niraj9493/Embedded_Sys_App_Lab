/*
 * steer_processor.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Niraj93
 */

#ifndef STEER_PROCESSOR_H_
#define STEER_PROCESSOR_H_

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include "steering.h"

/**
 * Assume that a threshold value is 50cm
 * Objective is to steer left or right based on the left and right sensor values
 * Example: If left sensor is 10cm, and right is 70cm, then we should call steer_right()
 */
void steer_processor(uint32_t left_sensor_cm, uint32_t right_sensor_cm);

#ifdef __cplusplus
}
#endif


#endif /* STEER_PROCESSOR_H_ */
