#ifndef INCLUDE_PRODUCER_H_
#define INCLUDE_PRODUCER_H_

extern pthread_mutex_t *producer_mutex;

class Producer {
    public:
        Producer();
        Producer(unsigned int id);
        void *produce(void *args);
        unsigned int getId();
        unsigned int getProductsOverLife();
        unsigned int getTotalProducts();
    private:
        unsigned int id;
        unsigned int total_prods;
        unsigned int prods_over_life;
};

#endif  // INCLUDE_PRODUCER_H_
