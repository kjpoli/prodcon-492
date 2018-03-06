pthread_cond_t *notEmpty;
pthread_mutex_t *consume_mutex;
pthread_mutex_t *queue_mutex;

int fn(int n) {
    if (n < 0) {
        return -1;
    } else if (n == 0 || n == 1) {
        return 1;
    } else {
        return fn(n - 1) + fn(n - 2);
    }
}

void *consume(void *id_void_ptr) {
    int *buffer = *(buffer *)id_void_ptr;

    while (true) {
        pthread_mutex_lock(mutex);
        
        while (buffer->empty) {
            pthread_cond_wait(notEmpty, mutex);
        }

        Product *p = buffer.remove();

        if (scheduler && p.getLife() >= quantum) {
            p.setLife(p.getLife() - quantum);
            
            for (int i = 0; i < quantum; ++i) {
                fn(10);
            }
            
            buffer.push(p);
        } else {
            for (int i = 0; i < p.getLife(); ++i) {
                fn(10);
            }
            
            std::cout << "Consumer id " << this->id << " consumed Product " << p->id << std::endl;
            delete *p;
            ++products_consumed;
        }
        
        usleep(10000);
        
        pthread_cond_signal(notFull, mutex);
        pthread_mutex_unlock(mutex);
    }

    pthread_exit(NULL);
}
