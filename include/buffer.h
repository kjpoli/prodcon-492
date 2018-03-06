#ifndef INCLUDE_BUFFER_H_
#define INCLUDE_BUFFER_H_

#include "product.h"

extern pthread_cond_t *notFull;
extern pthread_cond_t *notEmpty;
extern pthread_mutex_t *buffer_mutex;

class Buffer {
    public:
        Buffer(int max_size);
        void add(Product p);
        Product remove();
        unsigned int isEmpty();
        unsigned int getSize();
        unsigned int getMaxProducts();
    private:
        std::deque<Product *> queue;
        unsigned int max_size;
        unsigned int max_products;
};

#endif  // INCLUDE_BUFFER_H_
