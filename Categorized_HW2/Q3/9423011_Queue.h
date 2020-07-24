#include<string>

class Queue{
private:
  size_t N{};   //size of Queue  
  double *arr;  
  double * read;   
  double * write;
  bool flag_empty{false};  //if Queue is empty is true
  bool flag_full{false};
public:
  Queue(std::string);
  void displayQueue(void);
  void enQueue(double);
  double deQueue(void);
  ~Queue();
};
