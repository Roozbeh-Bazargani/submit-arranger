#include<iostream>
#include<fstream>
#include<string>

class Queue{
 public:
  size_t N;
  size_t top;
  size_t bottom;
  size_t intermediate;
  bool isFull;
  double *number;
  void enQueue(double);
  double deQueue();
  void displayQueue();

  Queue(std::string);
  ~Queue();
};
