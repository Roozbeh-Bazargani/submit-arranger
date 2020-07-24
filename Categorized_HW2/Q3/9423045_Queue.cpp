#include <iostream>
#include <fstream>
#include "Queue.h"



Queue::Queue(const char* s)
{
  std::ifstream input{ s }; //takes the text file
  input >> size; //size of the queue is first number in text file
  rpos = -1; //reading position and writing position is -1 for empty queue
  wpos = -1;
  nums = new double[size];//the queue

  for (size_t i = 0; i < size; i++)
    {
      if (!input.eof()) //until we have number in text and also size in queue
	{
	  input >> element;

	  char a;//getting separating white space
	  input >> a;
	  enQueue(element);//enqueue elements into array
	}
    }
}

void Queue::enQueue(double val)
{
  if (isempty())//making it point to the first element 
    {
      wpos = 0;
      rpos = 0;
    }
  else if (isfull())//error message 
    {
      std::cout << "Enqueue Failed ! Queue is full\n" << std::endl;
      return;
    }
  nums[wpos] = val;//write new value
  wpos = (wpos + 1) % _size;//updating write posotion

}

double Queue::deQueue()
{
  double res{};//result
  if (isempty())//error message
    {
      std::cout << "Dequeue Failed ! Queue is empty\n";
      return -1;
    }
  res = nums[rpos];//extract and delete 
  rpos = (rpos + 1) % size;
  if (rpos == wpos)
    {
      rpos = wpos = -1;
    }
  return res;
}

void Queue::displayQueue()
{
  if (isempty())
    {
      std::cout << "Nothing to display ! Queue is Empty\n";
      return;
    }
  for (size_t i = rpos; i% size != wpos; i++)//printing by order
    {
      std::cout << nums[i] << ' ';
    }
  std::cout << std::endl;
}

Queue::~Queue()
{
  delete[] nums;
}

//auxiliary functions explained completely in report
bool Queue::isempty()
{
  if (rpos == -1 && wpos == -1)
    {
      return true;
    }

  return false;

}
bool Queue::isfull()
{
  if (rpos == wpos && rpos != -1)
    {
      return true;
    }
  return false;
}
