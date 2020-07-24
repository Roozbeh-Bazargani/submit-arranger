#include<string>
//#include<fstream> 

class Queue{
  
 public:
  Queue(std::string myfile);
  ~Queue();
  void  displayQueue();
  void enQueue(double number);
  double deQueue();




 private:
  std::string filename;
  int L;
  char a;
  double* A;
  double* read;
  double* write;
  double s;


};
