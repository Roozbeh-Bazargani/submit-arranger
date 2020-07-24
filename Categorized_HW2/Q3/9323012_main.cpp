//this is main.cpp file 
#include<iostream>
#include<fstream>
#include"queue.h"

int main(){
  /*it reads the text file and reads size of queue and reads and 
  displays initial values from the file */
  Queue q{"Queue.txt"};
  /*here it adds 3 other values*/
  q.enQueue(15.5);
  q.enQueue(-6);
  q.enQueue(45);
  /*it displays all elements in queue*/
  q.display();
   /*because queue is full it shows an error of queue overflow!*/
  q.enQueue(405);

   /*the first and second elements of queue are deleted*/
  std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
  std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
  
  /*again it displays all elements*/
  q.display();

  return 0;

}
