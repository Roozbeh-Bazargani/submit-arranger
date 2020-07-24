#include<string>
#include<iostream>
#include<vector>

class Queue
{
 public:
  std::string filename;
  Queue(std::string filename);
    
  int size {};
  float newnum{};
  std::vector<float>v;
  int index{};
  float* write;
  float* read;
  float tmp;
  char ch;
  int count{};
  int distance;
   void displayQueue();
   void enQueue(float num);
   float* take;
   float deQueue();
   int flag{};

};


