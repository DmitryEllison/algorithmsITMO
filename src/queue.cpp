#include <cstdio>

#define QUEUE_MAX_SIZE 20
typedef int T;


typedef struct QUEUE_T {
    T data[QUEUE_MAX_SIZE];
    size_t size;
} queue_t;

bool is_empty(queue_t* queue) {
    return queue->size == 0;
}

size_t size(queue_t* queue) {
    return queue->size;
}

void push(queue_t* queue) {

}

T pop_min(queue_t* queue) {

}

void ma_test() {

}