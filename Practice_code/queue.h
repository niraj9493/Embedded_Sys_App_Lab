#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
  uint8_t queue_memory[100];
  int8_t front;
  int8_t rear;
  // TODO: Add more members as needed
} queue_S;

void queue__init(queue_S *queue);

bool queue__push(queue_S *queue, uint8_t push_value);

bool queue__pop(queue_S *queue, uint8_t* pop_value);

size_t queue__get_count(queue_S *queue);
