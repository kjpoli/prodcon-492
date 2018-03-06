#include "consumer.h"
#include "buffer.h"

pthread_mutex_t *consume_mutex = NULL;
int products_consumed = 0;

Consumer() {
    this->id = -1;
}

Consumer(unsigned int id) {
    this->id = id;
}


int fn(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return fn(n - 1) + fn(n - 2);
    }
}

void *consume(void *arg) {
    Buffer *buffer = *(buffer *)arg;

    while (products_consumed < buffer->getMaxProducts()) {
        pthread_mutex_lock(consumer_mutex);
        
        while (buffer->isEmpty()) {
            pthread_cond_wait(notEmpty, consumer_mutex);
        }

        pthread_mutex_lock(buffer_mutex);
        Product *p = buffer.remove();

        if (scheduler && (p.getLife() >= quantum)) {
            p.succLife(quantum);
            
            for (int i = 0; i < quantum; ++i) {
                fn(10);
            }
            
            buffer.add(p);
            pthread_mutex_unlock(buffer_mutex);
        } else {
            pthread_mutex_unlock(buffer_mutex);
            
            for (int i = 0; i < p.getLife(); ++i) {
                fn(10);
            }
            
            std::printf("Consumer id %d consumed Product %d", this->getId(), p->getId());
            delete *p;
            ++products_consumed;
        }
        
        usleep(10000);
        
        pthread_cond_signal(notFull);
        pthread_mutex_unlock(consume_mutex);
    }

    pthread_exit(NULL);
}

unsigned int getId() {
    return this->id;
}
