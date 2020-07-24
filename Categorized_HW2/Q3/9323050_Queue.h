#include<string>

class Queue{
 public:
    Queue(std::string filename);
    ~Queue();//destructor for deleting dynamic array
    void displayQueue();//showing func
    void enQueue(double num);//writing func
    double deQueue();//deleting func
 private:
    std::string name;//file's name
    int N;//total capacity of queue
    double* arr;//array that cantains member of queue
    char c;//charactor for putting , in it
    double* begin;//pointer that refer to the begining of queue
    double* end;//pointer that refer to the end of queue
    double ret;
    };
