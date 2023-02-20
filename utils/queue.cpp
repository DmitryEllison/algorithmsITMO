#include "utils.h"

bool is_empty(queue_t* queue) {
    return queue->size == 0;
}

size_t size(queue_t* queue) {
    return queue->size;
}

void swap(queue_t* queue, size_t i, size_t j) {
    T temp = queue->data[i];
    queue->data[i] = queue->data[j];
    queue->data[j] = temp;
}

void push(queue_t* queue, T elem) {
    if (queue->size >= QUEUE_MAX_SIZE) return;

    queue->data[queue->size++] = elem;
    size_t pos = queue->size;

    while (pos > 0 && queue->data[pos] < queue->data[(pos-1)/2]) {
        swap(queue, pos, (pos-1)/2);
        pos = (pos-1)/2;
    }
}

T pop(queue_t* queue) {
    T ans = queue->data[0];
    // change array log N
    queue->data[0] = queue->data[size(queue) - 1];
    size_t pos = 0;
    size_t min_son_index;

    while (pos * 2 + 2 < size(queue)) {
        // find min son
        min_son_index = queue->data[pos * 2 + 1] < queue->data[pos * 2 + 2] ?
                pos * 2 + 1 : pos * 2 + 2;
        if (queue->data[pos] > queue->data[min_son_index]) {
            swap(queue, pos, min_son_index);
            pos = min_son_index;
        } else break;
    }
    --queue->size;
    return ans;
}
