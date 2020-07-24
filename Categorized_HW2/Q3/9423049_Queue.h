#include<iostream>
#include<string>
#include<fstream>

class Queue {
 public:
  Queue(std::string );
  void displayQueue();
  void enQueue(double);
  double deQueue();
  ~Queue();
 private:
  int n{}; //size of array
  double* arr;//array
  int r{}; //show the place that we can read
  char m; //get comma between array
  double f;
  int w{};//show the place that we can write
};
