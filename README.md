# prodcon-492
Simulate a producer-consumer system using threads, mutexes, condition variables and scheduling.

usage: ./bin/run P1 P2 P3 P4 P5 P6 P7  
P1: Number of producer threads  
P2: Number of consumer threads  
P3: Total number of products to be generated by all producer threads  
P4: Size of the queue to store products for both producer and consumer threads (0 for
unlimited queue size)  
P5: 0 or 1 for type of scheduling algorithm: 0 for First-Come-First-Serve, and 1 for
Round-Robin  
P6: Value of quantum used for round-robin scheduling  
P7: Seed for random number generator  
