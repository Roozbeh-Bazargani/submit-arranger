#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include"Queue.h"

int main()
{
    Queue q{"Queue.txt"};

    // Display elements present in Circular Queue
    q.displayQueue();

    // Inserting elements in Circular Queue
    q.enQueue(15.5);
    q.enQueue(-6);
    q.enQueue(-6);
    q.enQueue(-6);

    q.displayQueue();
 
    // Deleting elements from Circular Queue
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
 
    q.displayQueue();
    q.enQueue(2.5);
    q.enQueue(2.5);
    q.displayQueue();
    std::cout<<"Deleted value = "<< q.deQueue() << std::endl;
    q.enQueue(2.5);
    return 0;
}
