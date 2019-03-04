#include "unity.h" // Single Unity Test Framework include
#include "Mocksteering.h"

#include "../Practice_code/steer_processor.h"


void test_steer_processor__move_left(void) {
    steer_left_Expect();
    steer_processor(90,20);
}

void test_steer_processor__move_right(void) {
    steer_right_Expect();
    steer_processor(40,45);
}

void test_steer_processor__both_sensors_less_than_threshold(void) {
    steer_right_Expect();
    steer_processor(10, 20);

    steer_left_Expect();
    steer_processor(20, 10);
}

void test_steer_processor__do_not_move(void) {
    steer_processor(100, 60);
    steer_processor(60, 100);
    steer_processor(30, 30);
    steer_processor(50,50);
}

// Do not modify this test case
// Modify your implementation of steer_processor() to make it pass
void test_steer_processor(void)
{
  steer_right_Expect();
  steer_processor(10, 20);

  steer_left_Expect();
  steer_processor(20, 10);
}
