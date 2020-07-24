#pragma once
class Queue
{
public:
  Queue(const char* );
  void displayQueue();
  void enQueue(double);
  double deQueue();
  ~Queue();
private:
  size_t rpos;
  size_t wpos;
  int size;
  double* nums;
  bool isempty();
  bool isfull();
  double element;
};

