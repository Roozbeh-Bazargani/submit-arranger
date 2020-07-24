#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

class Queue
{
 public:
  Queue(const std::string&); //constructor
  ~Queue(); //Destructor
	
  void displayQueue();
  void enQueue(double);
  std::string deQueue();
 private:
  size_t N{}, tail{}, cnt{};
  double *p;
};

