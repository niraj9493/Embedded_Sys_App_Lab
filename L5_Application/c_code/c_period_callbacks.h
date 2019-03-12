/**
 * @file
 *
 * The purpose of this "C" callbacks is to provide the code to be able
 * to call pure C functions and unit-test it in C test framework
 */
#ifndef C_PRD_CALLBACKS_H__
#define C_PRD_CALLBACKS_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "stddef.h"


bool C_period_init(void);
bool C_period_reg_tlm(void);
void C_period_1Hz(uint32_t count);
void C_period_10Hz(uint32_t count);
void C_period_100Hz(uint32_t count);
void C_period_1000Hz(uint32_t count);

#define LAB1 0      //<- Uses External Switch to generate Interrupt and toggles pin P2.6 for 500ms
#define LAB2 0      //<- UART communication between two boards - Takes Sensor value on board-1, displays on LED segment display on board2
#define LAB3TX 0      //<- CAN Communication Between two boards
#define LAB3RX 0      //<- CAN Communication Between two boards


#ifdef __cplusplus
}
#endif
#endif
