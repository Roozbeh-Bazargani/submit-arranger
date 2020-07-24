#include<string>
#include<iostream>
#include<vector>

class Queue {
 public:
  Queue(std::string txt);
  Queue() = default;
  void displayQueue();
  void enQueue(double val);
  double  deQueue();

 private:
  std::string txt;
  std::string str;
  int rear, front;
  double* arr;
  int N{};
  double deleted;
  
};
