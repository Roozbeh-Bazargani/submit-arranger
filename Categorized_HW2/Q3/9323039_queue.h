#include<string>
#include <fstream>
class Queue {

 public:
  Queue(std::string name);
 void enQueue(double a);
  double  deQueue();
  void displayQueue();
  

 private:
  char ch;
  int N;
  double *arr;
 int front;
 int rear;
 std::string name;

};
