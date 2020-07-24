class Queue {
 public:  
  Queue(std::string);  //  Constructor
  void enQueue(double);
  void displayQueue();  
  std::string deQueue();
  
 private:
  size_t n;  //  Number Of Elements
  double* p;  //  Queue Elements
  double* p_start;  //  The oldest elements
  double* p_end;  //  The newest elements
  double* p_current;  //  Current element to be written in
  size_t distance(); 
  void inc(double*&);
  bool isEmpty{true};  //  Flag to see if the queue is empty
};
