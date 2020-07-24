#include<iostream>

class Queue
{
 public:
  size_t queue_size{0}, queue_first_index{0}, queue_last_index{0};
  float* queue_members{new float[queue_size]};
  Queue(std::string address);
  void displayQueue();
  void enQueue(float input);
  float deQueue();
  bool full{false}; //when equeue is full or empty, queue_first_index and queue_last_index will be equal! for avoid mistaking, we use this bool
};
