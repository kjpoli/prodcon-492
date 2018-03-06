#include "buffer.h"
#include <stdlib.h>

Buffer(int size) {
    this-> queue = new std::deque<Product>();
    this-> size = size;
}

void add(Product p) {
    (this->queue).push_front(p);
}

Product remove() {
    Product temp = (this->queue).end();
    (this->queue).pop_back();
    return temp;
}

unsigned int getSize(){
    return this->size;
}
