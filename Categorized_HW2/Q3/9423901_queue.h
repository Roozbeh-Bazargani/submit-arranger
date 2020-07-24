#include<string>

class Queue {
 public:
  Queue(const char*);
  ~Queue();
  void displayQueue();
  void enQueue(double);
  double deQueue();
 private:
  std::string temp{};
  int start{}, end{};
  double tempout{};
  size_t length{}; //length of queue
  size_t number{}; //number of elements
  size_t Wposition{}, Rposition{};
  double* elements{}; //members of queue(numbers)
  
};
