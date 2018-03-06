#include "buffer.h"
#include <stdlib.h>

Buffer(unsigned int max_size) {
    this->queue = new std::deque<Product *>();
    this->max_size = max_size;
    this->max_products = max_products;
    pthread_mutex_init(&(this->buffer_mutex), NULL);
    pthread_cond_init(&(this->notEmpty), NULL);
    pthread_cond_init(&(this->notFull), NULL);
}

void add(Product p) {
    if (this->queue->size() < this->max_size) {
        (this->queue).push_front(p);
    }
}

Product remove() {
    if ((this->queue).size() > 0) {
        Product removed_product = (this->queue).end();
        (this->queue).pop_back();
        return removed_product;
    }
}

unsigned int isEmpty() {
    return (this->queue).empty();
}

unsigned int getSize() {
    return this->max_size;
}

unsigned int getMaxProducts() {
    return this->max_products;
}

unsigned int isFull() {
    return this->getSize() == (this->queue).size();
}
