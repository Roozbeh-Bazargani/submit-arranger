#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
class Queue {
 public:
  Queue(const char*);
  ~Queue();
  void displayQueue();
  void enQueue(const double);
  double deQueue();
 private:
  char* queName;
  size_t N;
  size_t lenQue, wpointer, rpointer;
  double* queArr;
};
