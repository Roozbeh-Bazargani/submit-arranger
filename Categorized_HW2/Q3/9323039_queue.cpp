#include"queue.h"
#include<iostream>

Queue::Queue(std::string name) : front{}
{
  std::cout<<"Constructor 1 called"<<std::endl;

    std::ifstream file{ name };

  file>>N;
  arr= new double [N];

  for (int i{}; i<N; i++)
    {   file>>arr[i]>>ch;
      if (arr[i] != 0)
	rear = i;
    }
}

void Queue::enQueue(double a)
{
  if (front == (rear + 1)%N )
    std::cout<<"Queue is full"<<std::endl;
  else {
    rear = (rear + 1)% N;
    arr[rear] = a;
    
  }

}

double Queue:: deQueue()
{
  double s{};
  if (front == rear )
    std::cout << "Queue is empty "<<std::endl;
  else {
    front = (front + 1 )%N;
    s = arr[front];
    arr [front] = 0;
  }
  return s;
}

void Queue :: displayQueue()
{
  for (int i{}; i<N; i++)
    {
      std:: cout<< arr[i]<< "\t";
    }
  std::cout<<std::endl;
}
