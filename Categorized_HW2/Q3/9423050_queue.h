#include <iostream>
#include <cstring>

class Queue{
 public:
  Queue(const char*);
  ~Queue();
  void displayQueue();
  void enQueue(double);
  std::string deQueue();
 private:
  size_t N , M{} , K; // M is number of inputs
  // N is size of Queue and K is checker
  bool F,E; // Full and Empty flags
  double* Ptr;
  
  
};
