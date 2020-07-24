//Mohammad Rahmdel 9423050
//Queue
#include <iostream>
#include "queue.h"

int main(){
  std::cout<<"Welcome"<<std::endl;
  Queue q("Queue.txt");
  q.displayQueue();
  q.enQueue(15.5);
  q.enQueue(-6);
  q.displayQueue();
  std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
  std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
  q.displayQueue();
  
 
  return 0;
}
