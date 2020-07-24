#include <string>
#include <vector>
using std::string;

class Queue{
 public:
  Queue (std::string file);
  void displayQueue();
  void enQueue(double);
  double deQueue ();
 private:
  std::string file;
  double* read;
  double* write;
  double temp{}, count{};
  double arr[7];
  char ch{};
  int i{}, n{}, m{};
  
};
