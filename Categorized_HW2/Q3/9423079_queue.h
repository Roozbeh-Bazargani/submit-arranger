
class Queue{
 public:
  Queue(std::string);
  Queue();
  ~Queue();
  void displayQueue(void);
  void enQueue(double new_elmnt);
  double deQueue(void);
  

 private:
  // Queue vars
  int size;
  int writerPos;
  int readerPos;
  double* elmnts;
  bool isSet;
  int allocated;
  // Queue methodls
  void updatePos(bool type);
  bool isFull(void);
  int realPos(int i);
  void errorPrinter(int eCode);
  std::vector<std::string> explode(std::string const & s, char delim);
  
};
