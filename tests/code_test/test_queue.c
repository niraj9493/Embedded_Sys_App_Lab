#include "queue.h"
#include "unity.h"

// void setUp(void) {
//   puts("\nsetUp() is called before each test_* function");
// }
// void tearDown(void) {
//   puts("\ntearDown() is called after each test_* function (unless test is ignored)");
// }

void test_queue_init(void)
{
    queue_S Q;
    queue__init(&Q);
    TEST_ASSERT_EQUAL(Q.front,-1);
    TEST_ASSERT_EQUAL(Q.rear,-1);
}

void test_queue_push(void)
{   
    queue_S Q[]=
    {
        {
            .queue_memory = {1,2,3,},
            .front = 0,
            .rear = 2
        },
        { 
            .queue_memory = {},
            .front = 0,
            .rear = 101,
        },
        {
            .queue_memory = {},
            .front = 10,
            .rear = 9,
        },
        {
            .queue_memory = {},
            .front = -1,
            .rear = -1,
        },
    };
    
    //Push
    TEST_ASSERT_GREATER_OR_EQUAL_INT8(Q[0].front, Q[0].rear);
    TEST_ASSERT_LESS_OR_EQUAL(100, Q[0].rear);
    TEST_ASSERT_FALSE(queue__push(&Q[0], 4));
    TEST_ASSERT_EQUAL(Q[0].queue_memory[Q[0].rear], 4);

    TEST_ASSERT_TRUE(queue__push(&Q[1], 4));
    TEST_ASSERT_TRUE(queue__push(&Q[2], 4));
    TEST_ASSERT_FALSE(queue__push(&Q[3], 1));
    
    //Checking memory elements after push
    TEST_ASSERT_EQUAL(1, Q[3].queue_memory[0]);
    TEST_ASSERT_EQUAL(0, Q[3].front);
    TEST_ASSERT_EQUAL(0, Q[3].rear);

}

void test_queue_pop(void)
{
    queue_S Q[] =
    {
        {
            .queue_memory = {1,2,4,},
            .front = 0,
            .rear = 2,
        },
        {
            .queue_memory = {},
            .front = -1,
            .rear = -1,
        },
        {
            .queue_memory = {1},
            .front = 0,
            .rear = 0,
        },
    };

    //Pop
    uint8_t deleted_val;
    uint8_t* pdeleted_val = &deleted_val;
    TEST_ASSERT_TRUE(queue__pop(&Q[1], pdeleted_val)); //poping from empty memory
    TEST_ASSERT_FALSE(queue__pop(&Q[0], pdeleted_val));
    TEST_ASSERT_EQUAL((uint8_t)1,deleted_val);
    TEST_ASSERT_FALSE(queue__pop(&Q[2], pdeleted_val));
    for (int i = 0; i < 3; i++)
    {
        TEST_ASSERT_GREATER_OR_EQUAL_INT8(Q[i].front, Q[i].rear);
    }
}
void test_queue_get_count(void)
{
    queue_S Q[] =
    {
        {
            .queue_memory = {1,2,4,},
            .front = 0,
            .rear = 2,
        },
    };

    TEST_ASSERT_EQUAL(3, queue__get_count(&Q[0]));
    queue__push(&Q[0], 5);
    TEST_ASSERT_EQUAL(4, queue__get_count(&Q[0]));
    queue__pop(&Q[0],NULL);
    TEST_ASSERT_EQUAL(3, queue__get_count(&Q[0]));
}