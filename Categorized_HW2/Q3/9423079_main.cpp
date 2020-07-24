#include<iostream>
#include "queue.h"

int main(){

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

     q.enQueue(12.2);
     q.enQueue(2.2);
     q.enQueue(1);
  q.displayQueue();
      std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
     std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
  q.displayQueue();
    q.enQueue(12.2);
     q.enQueue(2.2);
     q.enQueue(1);

     
     q.displayQueue();
     

  return 0;
}
