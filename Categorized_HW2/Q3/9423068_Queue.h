#include<string>
class Queue
{
  public:
  
  int rear,front;
  int size;
  double* arr;
  Queue(std::string file_name);
  ~Queue();
  void enQueue(double value);
  double deQueue();
  void displayQueue();
  
};
