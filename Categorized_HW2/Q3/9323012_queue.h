//this is a header file for Queue class

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<stdlib.h>

class Queue{
  //public methods and constructor and destructore
 public:
  Queue(std::string name);
  void display();
  Queue(Queue& q);
  void enQueue(double element);
  double deQueue();
  ~Queue();
  //private variables
 private:
  std::string name;
  std::ifstream file;
  std::string memory;
  std::string value;
  int memo;
  double num;
  int front;
  int rear;
  std::string word;
   double* arr;
  double data;
 };
