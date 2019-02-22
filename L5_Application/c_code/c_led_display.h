/*
 * c_led_display.h
 *
 *  Created on: Feb 18, 2019
 *      Author: Niraj93
 */

#ifndef C_LED_DISPLAY_H_
#define C_LED_DISPLAY_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

bool c_led_display_init(void);

void c_led_display_clear(void );

void c_led_display_set_number(char num);


#ifdef __cplusplus
}
#endif
#endif /* C_LED_DISPLAY_H_ */
