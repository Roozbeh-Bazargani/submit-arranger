/* M.Mehdi Naseri 9423115 */

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include"Queue.h"

Queue::Queue(std::string fileName)
{
    std::ifstream inFile;
    inFile.open(fileName); //open txt file
    if (!inFile) 
    {
        std::cout << "ERROR: Unable to open file" << std::endl; //unable to open txt file
        return;
    }
    else
    {
    	inFile >> capacity;
    	queue = new double[capacity];

    	std::string word{};
		inFile >> word; //all elements
		inFile.close(); //close the file
	    
	    length = 0;
	    readPoint = 0;
	    writePoint = 0;
	    std::string tempWord{}; //temporary stroring double numbers

	    /* Split Numbers */
	    for(char c : word)
	    {
	    	if(c != ',')
	    	{
	    		tempWord += c;
	    	}
	    	else
	    	{
	    		queue[length++] = atof(tempWord.c_str());
	    		writePoint++;
	    		if(writePoint == capacity)
	    			writePoint = 0;
	    		tempWord.erase(0); //erase tempWord content.
	    		if(length == capacity) //if we have more numbers than capacity, just ignore them
	    			break;
	    	}
	    }
	    if(length != capacity && length != 0) //for the last number
	    	{
	    		queue[length++] = atof(tempWord.c_str());
	    		writePoint++;
	    		if(writePoint == capacity)
					writePoint = 0;
	    	}

    }
}

Queue::Queue(Queue& Q)
{
	this->capacity = Q.capacity;
	this->length = Q.length;
	this->readPoint = Q.readPoint;
	this->writePoint = Q.writePoint;
	this->queue = new double[capacity];
	for(size_t i{0}; i < capacity; i++)
	{
		this->queue[i] = Q.queue[i];
	}
}

Queue::~Queue()
{
	delete[] queue;
}

void Queue::displayQueue()
{
	size_t readPointCopy = readPoint; //not changing readPoint
	std::cout << "Queue: ";
	for(size_t i{0}; i < length; i++)
	{
		std::cout << queue[readPointCopy++] << " ";
		if(readPointCopy == capacity)
			readPointCopy = 0;
	}
	std::cout << std::endl << "Queue Capacity: " << capacity << std::endl
				<< "Queue Length: " << length << "\n\n";
}

void Queue::enQueue(double element)
{
	if(length == capacity)
	{
		std::cout << "ERROR: Queue is FULL." << std::endl;
		return;
	}
	queue[writePoint++] = element;
	length++;
	if(writePoint == capacity)
		writePoint = 0;
}

double Queue::deQueue()
{
	if(length == 0)
	{
		std::cout << "ERROR: Queue is EMPTY." << std::endl;
		return 0;
	}
	length--;
	readPoint++;
	if(readPoint == capacity)
		{
			readPoint = 0;
			return queue[capacity - 1];
		}
	return queue[readPoint - 1];
}