//
//  main.cpp
//  Q3
//
//  Created by kian behzad on 12/7/1396 AP.
//  Copyright © 1396 AP kian behzad. All rights reserved.
//

#include <iostream>
#include "queue.hpp"

int main(int argc, const char * argv[]) {
    
    Queue q{"Queue.txt"};
    
    // Display elements present in Circular Queue
    q.displayQueue();
    
    // Inserting elements in Circular Queue
    q.enQueue(15.5);
    q.enQueue(-6);

    q.displayQueue();
    
    // Deleting elements from Circular Queue
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    
    q.displayQueue();

    return 0;
}
