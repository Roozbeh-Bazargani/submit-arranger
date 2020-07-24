#include<string>

class Queue{
 public:
  int firstFull;
  int lastEmpty;
  int queueLength;
  int numofElem;
  double* arrayofNumber;
  Queue(std::string text);
  void enQueue(double add);
  double deQueue();
  void displayQueue();
  ~Queue();
};
  
