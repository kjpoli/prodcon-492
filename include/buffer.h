#ifndef INCLUDE_BUFFER_H_
#define INCLUDE_BUFFER_H_

#include "product.h"

#include <pthread.h>
#include <deque>

extern pthread_cond_t *notFull;
extern pthread_cond_t *notEmpty;
extern pthread_mutex_t *buffer_mutex;

class Buffer {
    public:
        Buffer(int max_size);
        void add(Product p);
        Product remove();
        int isEmpty();
        int getSize();
        int getMaxProducts();
        int isFull();
    private:
        std::deque<Product> *queue;
        int max_size;
        unsigned int max_products;
};

#endif  // INCLUDE_BUFFER_H_
