#include "consumer.h"
#include "buffer.h"

#include <stdio.h>
#include <unistd.h>

pthread_mutex_t *consumer_mutex = NULL;
int products_consumed = 0;

Consumer::Consumer() {
    this->id = -1;
}

Consumer::Consumer(int id, int scheduler, int quantum) {
    this->id = id;
    this->scheduler = scheduler;
    this->quantum = quantum;
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

void Consumer::run(Buffer buffer) {
    pthread_create(thread, NULL, &consume, &buffer);
}

void* Consumer::consume(void *arg) {
    Buffer *buffer = (Buffer *) arg;

    while (products_consumed < buffer->getMaxProducts()) {
        pthread_mutex_lock(consumer_mutex);
        
        while (buffer->isEmpty()) {
            pthread_cond_wait(notEmpty, consumer_mutex);
        }

        pthread_mutex_lock(buffer_mutex);
        Product p = buffer->remove();

        if (getScheduler() && (p.getProductLife() >= getQuantum())) {
            p.setProductLife(getQuantum());
            
            for (int i = 0; i < getQuantum(); ++i) {
                fn(10);
            }
            
            buffer->add(p);
            pthread_mutex_unlock(buffer_mutex);
        } else {
            pthread_mutex_unlock(buffer_mutex);
            
            for (int i = 0; i < p.getProductLife(); ++i) {
                fn(10);
            }
            
            printf("Consumer id %d consumed Product %d", getId(), p.getProductId());
            ++products_consumed;
        }
        
        usleep(10000);
        
        pthread_cond_signal(notFull);
        pthread_mutex_unlock(consume_mutex);
    }

    pthread_exit(NULL);
}

int Consumer::getScheduler() {
    return scheduler;
}

int Consumer::getId() {
    return id;
}

int Consumer::getQuantum() {
    return quantum;
}
