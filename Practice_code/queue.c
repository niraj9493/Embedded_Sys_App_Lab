#include "queue.h"
#include <stdio.h>

void queue__init(queue_S *queue)
{
    queue->front = -1;
    queue->rear  = -1;
}
bool queue__push(queue_S *queue, uint8_t push_value)
{   
    if (queue->front > queue->rear || queue->rear > 100)
    {
        return true;
    }
    else
    {
        if (queue->front == -1)
            queue->front++;
        queue->rear++;
        queue->queue_memory[queue->rear] = push_value;
        return false;
    }
}


bool queue__pop(queue_S *queue, uint8_t* pop_value)
{   
    if (queue->front == -1 || queue->rear == -1)
    {
        return true;
    }
    else if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
        return false;
    }
    else
    {
        if(pop_value)
            *pop_value = (queue->queue_memory[0]);
        for (int8_t i = 0; i <= queue->rear; i++)
        {
            queue->queue_memory[i] = queue->queue_memory[i + 1]; 
        }
        queue->rear--;
        return false;
    }
}

size_t queue__get_count(queue_S *queue)
{
    return((size_t)queue->rear - queue->front + 1);
}