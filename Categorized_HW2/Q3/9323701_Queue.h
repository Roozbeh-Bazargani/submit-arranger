#include<string>
#include<iostream>
#include<fstream>

class Queue{
	public:
		Queue(std::string fileAddress);
		~Queue();
		void displayQueue();
		void enQueue(double value);
		double deQueue();
	private:
		int size{0};
		int readPointer{0};
		int writePointer{0};
		double* queue;
		
};
