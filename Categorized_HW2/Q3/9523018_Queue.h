#include <iostream>
#include <fstream>
#include <string>


class Queue {
public:
  double* Nums;
  Queue(std::string a);
  std::string f_name;
  void displayQueue();
  void enQueue(double);
  double deQueue();
  void handle_d();
  void handle_e();
  size_t e, d;
  size_t N;
};
