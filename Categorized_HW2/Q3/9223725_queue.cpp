#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>

#include"queue.h"

Queue::Queue(std::string str)
{
  std::ifstream in_file;
  in_file.open(str); //loading input file
  std::string line; //line varible for reading lines of file
  std::string nums; // numbers
  if(in_file.is_open())
    {
      size_t line_num{}; //number of lines in input file
      while(std::getline(in_file,line)) 
	{
	  if(line_num==0)
	    N=std::stoi(line); //1st line -> N
	  else
	    nums.append(line); //other lines->numbers, as a string
	  line_num++;
	}
    }
  std::stringstream ss{nums};
  in_file.close();
  front=0; //set front of sequence to 0
  arr=new double[N]; //initialization of array
  std::string temp;
  int idx{};
   
  while(std::getline(ss,temp,',')) //reading numbers from string to array
    {
      if(idx<N)
	arr[idx]=std::stod(temp);
      rear=idx++; //setting the end of sequence 
    }
  
}

void Queue::displayQueue()
{
  if(front==-1) //when seq is empty
    {
      std::cout<<"Queue is empty!"<<std::endl;
      return;
    }
  
  if(front<=rear) //when end of seq is after its front
    {
      std::cout<<"==========Queue=========== "<<std::endl;
      for(int i{front};i<=rear;i++)
	std::cout<<arr[i]<<std::endl;
    }
  else
    {
      std::cout<<"==========Queue==========="<<std::endl;
      for(int i{front};i<N;i++)
	std::cout<<arr[i]<<std::endl;
      for(int i{0};i<=rear;i++)
	std::cout<<arr[i]<<std::endl;
    }
  std::cout<<"=========================="<<std::endl;
}

void Queue::enQueue(double newNum)
{
  if((front==0 && rear==N-1) || (rear==front-1)) //when seq is full
    {
      std::cout<<"Queue is full"<<std::endl;
      return;
    }

  else if (front==-1)
    {
      front=rear=0;
      arr[rear]=newNum;

    }
  else if((rear==N-1) && front!=0)
    {
      rear=0;
      arr[rear]=newNum;

    }
  else
    {
      rear++;
      arr[rear]=newNum;

    }
  std::cout<<newNum<<" is inserted."<<std::endl;
  return;

}

double Queue::deQueue()
{
  double data{};
  if(front==-1)//when seq is empty
    {
      std::cout<<"Queue is empty"<<std::endl;
      return NAN;
    }
data=arr[front];

  if(front==(N-1))
      front=0;
  else if(front==rear)
      front=rear=-1;
  else
      front++;
  return data;
}

Queue::~Queue()
{
  delete[] arr; //deleting dynamic array
}
