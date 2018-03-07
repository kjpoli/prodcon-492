#include "buffer.h"
#include "product.h"

#include <stdlib.h>

Buffer::Buffer(int max_size) {
    this->queue = new std::deque<Product>;
    this->max_size = max_size;
    this->max_products = max_products;
}

void Buffer::add(Product p) {
    if (this->queue->size() < this->max_size) {
        this->queue->push_front(p);
    }
}

Product Buffer::remove() {
    if (this->queue->size() > 0) {
        Product removed_product = this->queue->back();
        this->queue->pop_back();
        return removed_product;
    }
}

int Buffer::isEmpty() {
    return this->queue->empty();
}

int Buffer::getSize() {
    return this->max_size;
}

int Buffer::getMaxProducts() {
    return this->max_products;
}

int Buffer::isFull() {
    return this->getSize() == this->queue->size();
}
