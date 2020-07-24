// By Navid Hasanzadeh 9323701
#include"Queue.h"
#include<sstream>
Queue::Queue(std::string fileAddress){
	std::ifstream File;
	// open the queue file
	File.open(fileAddress);
	bool isFirstLine{true};
	std::string line;
	// read the file line by line
	while(std::getline(File,line))
{
    std::stringstream   linestream(line);
    std::string         value;
    // We know that in the first line, the size of queue is determined,
    if (isFirstLine){
		getline(linestream,value);
		size = std::stoi(value);
		// make a queue with the determined size.
		queue = new double[size];
		isFirstLine = false;
	}else
	{	
	// split the next line with ',' delimiter and save each part into the value string,
    while(getline(linestream,value,','))
    {
		queue[writePointer] = stod(value);
	// change writePointer position
		writePointer++;	
    }
}
}
}
Queue::~Queue(){
	delete[] queue;
}
// display all queue elements
void Queue::displayQueue(){
	for(int i{readPointer}; i < writePointer; i++)
		std::cout << queue[i%size] << " ";
	std::cout << std::endl;	
}
//insert a new element in queue
void Queue::enQueue(double value){
	if(writePointer - readPointer == size)
		std::cout << "Queue is full." << std::endl;
	else
	{
		queue[writePointer % size] = value;
		writePointer ++;
	}	
}
//delete the first element from queue
double Queue::deQueue(){
	if(readPointer >= writePointer)
		std::cout << "Queue is empty" << std::endl;
	else
	{
		readPointer++;
		return queue[readPointer-1];
	}
	return 0;
}
