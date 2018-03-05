#include <stdlib.h>

#include "product.h"

Product() {
    this->id = -1;
    this->time_stamp = clock();
    this->life = std::rand() % 1024;
}

Product(int id) {
    this->id = id;
    this->time_stamp = clock();
    this->life = std::rand() % 1024;
}

int getProductId() {
    return this->id;
}

time_t getProductTime() {
    return this->time_stamp;
}

unsigned int getProductLife() {
    return this->life;
}
