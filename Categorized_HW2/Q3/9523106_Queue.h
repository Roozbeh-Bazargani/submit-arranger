#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

class Queue
{
public:
	Queue(std::string);
	void displayQueue();
	void enQueue(double);
	std::string deQueue();
	~Queue();
private:
	//current: first index which has value
	//length: the whole length of the array
	//n: number of values in the array
	size_t current, length, n;
	double* arr;
};

