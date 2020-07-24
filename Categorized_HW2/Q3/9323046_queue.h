//Created By Mohammad Sadegh safari 9323046

#include<iostream>

class Queue{
  //declatring private variables
  size_t size{}, readposition{0}, writeposition{0};
  bool full{false};
  double* values{};

  //declaring public variable and functions
  public:
  const char* a;
  Queue(const char* );
  ~Queue();
  void displayQueue() const;
  void enQueue(double);
  double deQueue();
};
