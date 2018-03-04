//#include "procon.h"
//#include "pthread.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

class Producer {
        string id;
        int total_prods;
        int prods_over_life;

        void produce() {
            if(prods_over_life != total_prods){
                Product P = new Product(id + to_string(prods_over_life));
            }
        }
        
}

class Buffer {
        pthread_cond_t full;
        pthread_cond_t hasItem;
        unsigned int size;
        deque<Product> queue;

        Buffer(int qsize){
            size = qsize;
        }
        
        void add(){
            
        }
        void remove() {
            
        }
}

class Product {
        string id;
        time_t tstamp;
        unsigned int life;
        //product uids im thinking can be in the form of x(y+) where x is an alphabetical id for the producer and y are sequential numerical ids for its products
        Product(string uid){
            id = uid;
            life = std::rand()%1024;
            // the current time and day from the system clock wrapped in a time_t 
            tstamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            
        }
        
};
//struct for storing the statistics, one instantiated for each algorithm later 
    struct stats {
        int total_time;
        int turnaround[3];
        int average[3];
        int prod_throughput;
        int con_throughput;
    };

int main(int argc, char** argv){
    
    if(argc != 8) { printf("%s", "missing args"); return 1; }
    int args[7]; 
    for(int i = 1; i < 8; ++i){
        args[i] = atoi(argv[i]);
    }
    
    const struct {
    int prod_threads;
    int con_threads;
    int total_prods;
    int queue_size;
    // 0 for FCFS 1 for Round Robin
    int scheduler;
    int quantum;
    int seed;
    } params { args[0],args[1],args[2],args[3],args[4],args[5],args[6] };
    std::srand(params.seed);

    
    return 0;
}
