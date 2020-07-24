#include<string>

class Queue {
  public:
  char ch{};
  int front{}, rear{};
  std::string* num;
  int SIZE{};
  std::string I{};
  Queue (int SIZE);
  Queue (std::string I);
  void enQueue (double);
  double deQueue ();
  void displayQueue();
 };
