#include "Queue.h"



Queue::Queue(std::string file)
{
	char x;		//for saving the ,
	size_t cnt{};
	std::ifstream inFile;
	inFile.open(file);
	if (inFile) {
		inFile >> length;
		arr = new double[length]; //creating the array
		while(cnt < length - 2) {
			inFile >> arr[cnt++] >> x;
		}
		inFile >> arr[cnt];
		current = 0;
		n = cnt - 1;
	}
	else {
		std::cout << "Failed to open file" << std::endl;
	}

}

//displaying the array
void Queue::displayQueue()
{
	for (size_t i{ current }; i < current + n; i++)
		std::cout << arr[i] << "  ";
	std::cout << std::endl;
}

void Queue::enQueue(double a)
{
	if (n == length) {	//incase the array is full
		std::cout << "Error! The array is full" << std::endl;
	}
	else
	{	//incase the last index was full and the initail indexes was empty
		arr[(current + n++) % length] = a;
	}
}

std::string Queue::deQueue()
{
	std::ostringstream s{};
	s << arr[current];
	if (n == 0)
		return "Error! The array is empty\n";
	else if (current == length - 1)//incase the index was the last
		current = 0;
	else
		current++;
	n--;
	return s.str();
}


Queue::~Queue()
{
	delete[] arr;
}
