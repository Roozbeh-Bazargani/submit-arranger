#include<string>
#include<vector>
class Queue {
 public:
  Queue(std::string);
  void displayQueue();
  void enQueue(double);
  double deQueue();
  ~Queue();
 private:
  double *arr;
  int N{};
  int front{-1};
  int rear{-1};
};
