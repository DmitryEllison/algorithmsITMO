#include <cstdio>

#define QUEUE_MAX_SIZE 1024
typedef int T;

typedef struct QUEUE_T {
    T data[QUEUE_MAX_SIZE];
    size_t size;
} queue_t;

/**
 * @param queue
 * @return true if queue is empty
 */
bool is_empty(queue_t* queue);

/**
 * @param queue
 * @return size of the queue
 */
size_t size(queue_t* queue);

/**
 * Push the T element to the queue
 * @param queue
 * @param elem
 */
void push(queue_t* queue, T elem);

/**
 * Return minimum of the queue and delete it
 * @param queue
 * @return
 */
T pop(queue_t* queue);
