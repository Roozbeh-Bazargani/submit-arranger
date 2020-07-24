#include"Queue.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

Queue::Queue (int size) {
  SIZE = size;
  rear = -1;
  front = -1;
  num = new std::string[SIZE];
  std::cout << "created" << std::endl;
}
Queue::Queue(std::string i){
  rear = -1;
  front=-1;
  I = i;
  std::string txt{};
  std::ifstream ifile{I};
  int a{};
  ifile >> a;
  SIZE = a;
  std::cout << SIZE << std::endl;
  num = new std::string[SIZE];
  while(!ifile.eof()){    //get the txt file line by line
    getline(ifile, txt);
    std::cout << txt << std::endl;//
    size_t start{txt.find_first_not_of(",")}; //first word start index
    size_t end{}; //index for end of the word
    for(int i=0; i < SIZE; i++){
       while(start != std::string::npos){ //find the words
          end = txt.find_first_of(",",start + 1); //find end of word
          if(end == std::string::npos) //found a seprator?
	     end = txt.length();//if not go forward
          num[i] = txt.substr(start, end - start);//store the word
          std::cout << num[i] << std::endl;
          rear++;
          front = 0;
          start = txt.find_first_not_of(",", end + 1);//find the first char of next word
          }
        }
     }
  }
void Queue::enQueue (double value){
  std::string v = std::to_string (value);
  bool Full{(rear + 1)% SIZE == front};
  if(Full){
      std::cout << "queue is full" << std::endl;
         }
   else
      {
      rear = (rear+1) % SIZE;
      num[rear] = v;
      if(front == -1)
        front = rear;
      std::cout << "added" << std::endl;  
      }
   }
double Queue::deQueue () {
  if (front == -1){
      std::cout << "it's empty" << std::endl;
      return 1;
    }
   else{
      std::string data = num[front];
      if(rear == front)
	  front = rear = -1;
      else
	   front = (front + 1) % SIZE;
       std::cout << "deleted" << std::endl;
       std::cout << "data issss:" << data << std::endl;
       std::cout << "front is;" << front << std::endl;
       double db = std::stod (data);
       return db;
       }
   }
void Queue::displayQueue(){
     if(front==-1){
       std::cout << "Queue is empty" << std::endl;
       return;
       }
     std::cout << "elements are:" << std::endl;
     if(rear >= front){
        for(int i=front; i <= rear; i++)
           std::cout << num[i] << std::endl;
	}
     else
        {
         for(int i=front; i <= SIZE; i++)
             std::cout << num[i] << std::endl;
         for(int i=0; i< SIZE; i++)
	     std::cout << num[i] << std::endl;
         }
     }
	
