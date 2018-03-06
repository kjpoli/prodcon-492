#ifndef INCLUDE_PRODUCT_H_
#define INCLUDE_PRODUCT_H_

#ifndef TIME_H_
#define TIME_H_
#include <time.h>
#endif  // TIME_H_

class Product {
    public:
        Product();
        Product(unsigned int id);
        unsigned int getProductId();
        time_t getProductTime();
        unsigned int getProductLife();
        void setProductLife(unsigned int q);
    private:
        unsigned int id;
        time_t time_stamp;
        unsigned int life;
};

#endif  // INCLUDE_PRODUCT_H_
