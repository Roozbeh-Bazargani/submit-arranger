#include<iostream>
#include<fstream>
#include"Queue.h"

int main(){
  Queue q{"Queue.txt"};

  //Display elements present in circular Queue
  q.displayQueue();

  //Inserting elements in circular Queue
  q.enQueue(15.5);
  q.enQueue(-6);

  q.displayQueue();

  //Delelting elements in circular Queue
  std::cout << "Deleted value = " << q.deQueue() << std::endl;
  std::cout << "Deleted value = " << q.deQueue() << std::endl;

  q.displayQueue();
  return 0;
}
