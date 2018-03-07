#include "producer.h"
#include "buffer.h"

#include <stdlib.h>

pthread_mutex_t *produce_mutex = NULL;

unsigned int products_produced = 0;

Producer::Producer() {
    this->id = -1;
    this->products_over_life = 0;
}

Producer::Producer(int id) {
    this->id = id;
    this->products_over_life = 0;
}

static void *produce(void *arg) {
    Buffer *buffer = *(buffer *)arg;

    while(products_produced < buffer->getMaxProducts()){
        pthread_mutex_lock(producer_mutex);
        
        while (buffer->isEmpty()) {
            pthread_cond_wait(notFull, producer_mutex);
        }

        pthread_mutex_lock(buffer_mutex);
        Product p = new Product((this->prods_over_life));
        b.add(p);
        this->prods_over_life = ++(this->prods_over_life);
        pthread_mutex_unlock(buffer_mutex);

        pthread_cond_signal(notEmpty);
        pthread_mutex_unlock(producer_mutex);
    }

    this->setProductsOverLife(products_over_life);
    pthread_exit(NULL);
}

int Producer::getId() {
    return this->id;
}

unsigned int Producer::getTotalProducts() {
    return this->total_prods;
}

unsigned int Producer::getProductsOverLife() {
    return this->prods_over_life;
}
