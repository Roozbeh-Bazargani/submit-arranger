/*
AP-HW2-Q3
9423054
*/

//Class header file

#include<iostream>


class Queue
{
 public:

  Queue (const char*); //constructor
  Queue (); //default constructor
  void  displayQueue();  //prints the Queue
  void enQueue(double);  //adds element to Queue
  void enQueue();        //in case that there's no input
  double deQueue();      //deleting from Queue
    ~Queue();

 private:

  size_t size{};       //size of Queue
  size_t write{};      //points to first added element
  size_t read{};       //points to last added element
  double value{};      //returned value from deQueue
   double* nums;        //array to show the Queue
  char tmp{};          //stores char input of file
};
