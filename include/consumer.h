#ifndef INCLUDE_CONSUMER_H_
#define INCLUDE_CONSUMER_H_

#include <pthread.h>

extern pthread_mutex_t *consume_mutex;

class Consumer {
    public:
        Consumer();
        Consumer(int id, int scheduler, int quantum);
        static void *consume(void *args);
        static int getId();
        static int getScheduler();
        static int getQuantum();
    private:
        int id;
        int scheduler;
        int quantum;
};

#endif  // INCLUDE_CONSUMER_H_
