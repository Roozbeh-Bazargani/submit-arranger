#include"Queue.h"
#include<iostream>
#include<fstream>
 
Queue::Queue(std::string myfile){
 
  std::cout<<"constructor1"<<std::endl;
  filename=myfile;
  std::ifstream ifile{filename}; //creat file object.
  ifile>>L;// get the first number as  the arrey length.
  A=new double [L]; 
  ifile>>A[0]>>a>>A[1]>>a>>A[2]>>a>>A[3]; //get the data  from the file & store in the dynamic array.

  read=A; //initial value the read pointer(
  write=A+3; //initial value the write  pointer
   
}


void  Queue::displayQueue()  // definition of displayQueue function.
{
  for(int i{};i<L;i++)    //the loop for display array members.
    { 
      std::cout<<A[i]<<std::endl;
    }
}

void Queue::enQueue(double number)   // definition of enQueue function.
{
  if((abs(write-read)<=6)&& (abs(read-write)>1))  //the condition of free space
    {
      if(write<A+6)
	{
	  *(write+1)=number;
	  write++;
	  std::cout<<"Your data was saved with a numeric value of "<<number<<std::endl;
	}
      if(write == A+6)  //condition for when the pointer point the end of array.
	{
	  write=A-1;   
     
        }
    
    }
  else
      std::cout<<"There is not enough space to store your data."<<std::endl;
}


double Queue::deQueue()   // definition of deQueue function.
{
  if(read < A+7)
    {
  s=*read;
  read++;
    }
  if(read == A+7)
    {
      read=A;
     }  
      return s;     
}

Queue::~Queue() // // definition of destructot function for delete dynamic array.
{
  std::cout<<"destructor"<<std::endl;
  delete[] A;
}









