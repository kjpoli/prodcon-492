#include "product.h"

#include <stdlib.h>

Product::Product() {
    this->id = 0;
    this->time_stamp = clock();
    this->life = std::rand() % 1024;
}

Product::Product(unsigned int id) {
    this->id = id;
    this->time_stamp = clock();
    this->life = std::rand() % 1024;
}

unsigned int Product::getProductId() {
    return this->id;
}

time_t Product::getProductTime() {
    return this->time_stamp;
}

unsigned int Product::getProductLife() {
    return this->life;
}

void Product::setProductLife(unsigned int q) {
    if (this->life >= q) {
        this->life = this->life - q;
    }
}
