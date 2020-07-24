#include<iostream>
#include<fstream>
#include<string>
#include"Queue.h"
// constructor of class Queue
Queue::Queue(std::string file_name)
{
  // front is the first num location
  // rear is last num location
  front=rear=-1;
  std::ifstream myfile{ file_name };
  myfile >> size;
  // make dinamic array for Queue 
  arr= new double [size];
  double num;
  char ch;
  std::cout << "Size of Queue is: " << size << std::endl;
  // take value from text file
  while(myfile >> num )
    {
      myfile >> ch;
      // add num from file to Queue by enQueue(value) function of class
      enQueue(num);
    }
  myfile.close();
}


void Queue::enQueue(double value)
{
  // check Queue if be full 
  if((front==0 && rear==size-1)||(rear==front-1))
    {
      std::cout << "Queue is full" << std::endl;
    }
  // add the first value
  else if(front==-1)
    {
      front=rear=0;
      arr[rear]=value;
    }
  /* if the front of Queue is empty and rear reach end of Queue,
     add value to Queue*/
  else if((rear==size-1) && front != 0)
    {
      rear=0;
      arr[rear]=value; 
    }
  // if the rear of Queue has empty place
  else
    {
      rear++;
      arr[rear]=value;
    }
}
// deleting value from front of Queue function
double Queue::deQueue()
{
  double deleted = arr[front];
  // check Queue is empty
  if(front == -1)
    {
      std::cout << "Queue is empty" << std::endl;
      return 0;
    }

    if(front == rear)
      {
	front=-1;
	rear=-1;
      }
    else if(front == size-1)
      {
	front=0;
      }
    else{ front++; }
    return deleted;
}

void Queue::displayQueue()
{
  // if Queue is empty, print and return
  if(front==-1)
    {
      std::cout << "There is no elements in Queue" << std::endl;
      return;
    }
  if(front <= rear)
    {
      for(int i{front}; i <= rear; i++)
	{
	  std::cout << arr[i] << "\t";
	}
      std::cout << std::endl;
    }
  else
    {
      for(int i=front; i < size; i++)
	{
	  std::cout << arr[i] << "\t";
	}
      for(int i=0; i<=rear; i++)
	{
	  std::cout << arr[i] << "\t";
	}
      std::cout << std::endl;

    }
}
Queue::~Queue(){
  delete [] arr;
}
