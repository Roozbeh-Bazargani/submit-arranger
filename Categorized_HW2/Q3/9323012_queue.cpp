/* constructors and methods and distructor for queue class*/
#include"queue.h"

Queue::Queue(std::string name)
{
  front = rear =-1;
  arr = new double[memo];
  this -> name = name;
  file.open(name);
  std::getline(file,memory);
  std::stringstream(memory) >> memo;
  
    while(std::getline(file,value))
    {
      if(value != memory){
	std::stringstream val(value);
	while(std::getline(val,word,',')){
	  std::stringstream(word) >> num;
	  if(front == -1 ){
	    rear = front = 0;
	    arr[rear] = num;}
	  else{
	    rear++;
	    arr[rear] = num;}
	}
      }
    }
    std::cout<<"elements in Queue from file are: "<<std::endl;
  if (rear >= front)
    for (int i{front}; i<=rear; i++)
      std::cout<<arr[i]<<std::endl;
}
Queue::Queue(Queue& q){
  front = q.front;
  rear = q.rear;
  this->memo = q.memo;
  data = q.data;
  arr = new double[memo];
  for(int i{};i<memo ;i++)
    arr[i] = q.arr[i];
}
void Queue::enQueue(double element){
  if((front == 0 && rear == memo-1)||(rear == front-1)){
      std::cout << "Queue overflow!" << std::endl;
      return;}
  else if(front == -1 ){
	rear = front = 0;
	arr[rear] = element;}
  else if(rear == memo-1 && front !=0){
    rear = 0;
    arr[rear] = element;}
  else{
    rear++;
    arr[rear] = element;}
}

double Queue::deQueue()
{
  if (front == -1)
    std::cout<<"Queue is empty!"<<std::endl;
  data = arr[front];
  arr[front] = -1;
  if (front == rear)
    {
      front = -1;
      rear =-1;
    }
  else if (front == memo-1)
    front =0;
  else
    front++;
  return data;
} 
void Queue::display()
{
  if(front == -1){
    std::cout<<"Queue is empty!"<<std::endl;
    return;}
  std::cout<<"elements in Queue are: "<<std::endl;
  if (rear >= front)
    for (int i{front}; i<=rear; i++)
      std::cout<<arr[i]<<std::endl;
  else
    {
      for(int i{front}; i< memo; i++)
	std::cout<<arr[i]<<std::endl;
      for(int i{}; i<= rear; i++)
	std::cout<<arr[i]<<std::endl; 
    }
}

Queue::~Queue(){

  delete[] arr;
}
