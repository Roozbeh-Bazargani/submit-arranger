#include <iostream>
#include <string>
#include <fstream>
class Queue{
public:
	Queue(std::string);
	~Queue();
	void displayQueue();
 	void enQueue(float);
	float deQueue();
private:
	int location;
	int len;
	float* pointer;
};
