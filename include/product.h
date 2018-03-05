#ifndef PRODCON_PRODUCT_H_
#define PRODCON_PRODUCT_H_

class Product {
    private:
        int id;
        time_t time_stamp;
        unsigned int life;
    public:
        Product();
        Product(int id);
        
        int getProductId();
        time_t getProductTime();
        unsigned int getProductLife();
}

#endif  // PRODCON_PRODUCT_H_
