#ifndef INCLUDE_BUFFER_H_
#define INCLUDE_BUFFER_H_

class Buffer {
    public:
        Buffer(int size);
        void add();
        Product remove();
        unsigned int getSize();
        
    private:
        deque<Product> queue;
        pthread_cond_t hasSpace;
        pthread_cond_t notEmpty;
        unsigned int size;
        
}

#endif
