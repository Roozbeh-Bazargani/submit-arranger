#include <string>
class Queue {
 public:
  Queue(std::string Qtxt); //constructor
  void displayQueue();
  void enQueue(double);
  double deQueue();
  ~Queue(); //destructor
 private:
  double* Readptr{}; //pointer to read position
  double* Writeptr{}; //pointer to write position
  int Qlength{}; //queue length
  int elementNum{}; //how many elements are in the queue
  double* cirQueue{}; //queue first memory pointer
};


