#include "producer.h"
#include <stdlib.h>

Producer() {
    this->id = -1;
    this-> total_prods = 0;
    this-> prods_over_life = 0;
    this-> lock = pthread_mutex_init();
}

Producer(int id, int max) {
    this->id = id;
    this->total_prods = max;
    this->prods_over_life = 0;
}

void *produce(Buffer b){
    if(this->prods_over_life == this->total_prods){
        //destroy this producer
        return;
    }
    while(true){
        pthread_mutex_lock(&(this->lock));
        pthread_cond_wait(&(b->hasSpace),&(this->lock));
        Product p = new Product((this->prods_over_life));
        b.add(p);
        this->prods_over_life = ++(this->prods_over_life);
        pthread_mutex_unlock(&(this->lock));
    }
    return; 
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

pthread_mutex_t getLock(){
    return this->lock;
}
