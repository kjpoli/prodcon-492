#ifndef INCLUDE_PRODUCT_H_
#define INCLUDE_PRODUCT_H_

class Product {
    public:
        Product();
        Product(int id);
        int getProductId();
        time_t getProductTime();
        unsigned int getProductLife();
    private:
        int id;
        time_t time_stamp;
}

#endif  // INCLUDE_PRODUCT_H_
