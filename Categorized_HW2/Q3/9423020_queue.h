#include<string>

class Queue
{
public:
int front;
int rear;
int qsize;
Queue();
Queue(std::string fileName);
Queue(const Queue&);
~Queue();
double* queueArray{};
void enQueue(int newNum);
void displayQueue();
int deQueue();
bool full();
};
