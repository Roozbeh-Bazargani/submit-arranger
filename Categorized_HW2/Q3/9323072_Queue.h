#include<string>



class Queue{
 public:
  int end, front, length, size;
  double* q;
  std::string Text;
  Queue(std::string text);
  void enQueue(double x);
  double deQueue();
  void displayQueue();
  bool isEmpty();
  ~Queue();

 private:
    void makeQueue();

};
