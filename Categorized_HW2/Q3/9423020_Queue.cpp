#include"queue.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
Queue::Queue(std::string fileName)
{
	std::string tempcontent;
	std::string tempsize;
	std::cout << "constructor called" << std::endl;
	std::ifstream file(fileName);
	std::getline(file, tempsize);
	qsize = std::stoi(tempsize);
	queueArray = new double[qsize];
	std::getline(file, tempcontent);
	const std::string separator{","}; //to locate the words
	size_t start{ tempcontent.find_first_not_of(separator)}; 
	//the index of first word
	size_t end{};
	size_t i{};
	while(start != std::string::npos)
	{
		end = tempcontent.find_first_of(separator, start + 1);
		if (end == std::string::npos)
		{
		   end = tempcontent.length();
		}
		queueArray[i] = std::stod(tempcontent.substr(start, end - start));
		start = tempcontent.find_first_not_of(separator, end + 1);
		i += 1;
	}
rear = i;
front = 0; 
}

Queue::Queue() {}

Queue::Queue(const Queue& a)
{
std::cout << "copyconstructor called" << std::endl;
qsize = a.qsize;
queueArray = new double[qsize];
for(size_t i{}; i < qsize; i++)
{
	queueArray[i] = a.queueArray[i];
}
}

Queue::~Queue()
{
	std::cout << "Destructor called" << std::endl;
	delete[] queueArray;
}

void Queue::enQueue(int newNum)
{
	if(full())
	  std::cout << "it can not be added" << std::endl;
 	else if( rear < qsize - 1 )
	  {
	      queueArray[rear + 1] = newNum;
	      rear +=1;
	  }
	else 
	{
	  rear = 0;
	  queueArray[rear];
	}
}

int  Queue::deQueue()
{
double temp{queueArray[front]};
queueArray[front] = 0;
front +=1;
return temp;
}

void Queue::displayQueue()
{
 std::cout << "display it" << std::endl;
}
bool Queue::full()
{
if((front == 0 && rear == qsize - 1) || (front != 0 && rear != 0 && front == rear))
return true;
else
return false;
}
