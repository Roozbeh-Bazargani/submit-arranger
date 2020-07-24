#include "Queue.h"
#include<iostream>
#include<fstream>

Queue::Queue(std::string filename)
{
  std::cout<<"constructor 1 called"<<std::endl;
  name=filename;
  std::ifstream myfile{name};//opening the file 
  myfile>>N;//putting the amount of capacity into N
  arr=new double[N];
  myfile>>arr[0]>>c>>arr[1]>>c>>arr[2]>>c>>arr[3];
  begin=arr;//point to full space
  end=arr+3;//point to full space
}

void Queue::displayQueue()
{
  //printing the queue
  std::cout<<"Members of queue are like this:"<<std::endl;
  for(int i{};i<N;i++)
    {
      std::cout<<arr[i]<<",";
    }
  std::cout<<std::endl;
}

void Queue::enQueue(double num)
{ 
  if((abs(end-begin) <= 6) && (abs(begin-end)>1))//considering different states
    {
      if(end<(arr+6))
	{
	  *(end+1)=num;
	  end++;
	}
      else if(end==(arr+6))
	{
	  if(begin>arr)
	    {
	      end=arr;
	     *end=num;
	    }
	  else
	    {
	      std::cout<<"Error!!Queue is full.you can't write anything"<<std::endl;
	    }
	}
    }
  else
    {
       std::cout<<"Error!!Queue is full.you can't write anything"<<std::endl;
    }
 }

double Queue::deQueue()
{
  if(*begin ==0)//if pointer is refering to empty space
    {
      std::cout<<"Error.this place is empty you can't delete it."<<std::endl;
      return 0;
    }
  else
    {
      if(begin <(arr+6))
       {
        ret=*begin;
        *begin=0;
        begin++;
       }
      else if(begin==(arr+6))//if it points to the end of queue
       {
        ret=*begin;
        *begin=0;
        begin=arr;  
       }
     return ret;
    }
  
}
      
  

Queue::~Queue()
{
  std::cout<<"deleted"<<std::endl;
  delete[]arr;
}


