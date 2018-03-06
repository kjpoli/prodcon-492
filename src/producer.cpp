#include "producer.h"
#include "buffer.h"

#include <stdlib.h>

pthread_mutex_t *produce_mutex = NULL;

unsigned int products_produced = 0;

Producer() {
    this->id = -1;
    this->products_over_life = 0;
}

Producer(unsigned int id) {
    this->id = id;
    this->products_over_life = 0;
}

void *produce(void *arg) {
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

unsigned int getId() {
    return this->id;
}

unsigned int getTotalProducts() {
    return this->total_prods;
}

unsigned int getProductsOverLife() {
    return this->prods_over_life;
}
