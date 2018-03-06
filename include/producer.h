#ifndef INCLUDE_PRODUCER_H_
#define INCLUDE_PRODUCER_H_

class Producer {
    public:
        Producer();
        Producer(int id,int max);
        void* produce(Buffer b);
        unsigned int getId();
        unsigned int getProductsOverLife();
        unsigned int getTotalProducts();
        pthread_mutex_t getLock();
    private:
        int id;
        int total_prods;
        int prods_over_life;
        pthread_mutex_t lock;
}

#endif  // INCLUDE_PRODUCER_H_
