#ifndef INCLUDE_CONSUMER_H_
#define INCLUDE_CONSUMER_H_

class Consumer {
    public:
        Consumer();
        Consumer(int id);
        void *consume(void *args);
        unsigned int getId();
        pthread_mutex_t consumeMutex();
    private:
        unsigned int id;
        pthread_mutex_t lock;
};

#endif  // INCLUDE_CONSUMER_H_
