#include"Queue.h"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

/* constructor of the class , front is the front of the queue and end is the first empty of array
   and size is the number of the queue element and text is the file name that constructor get*/
Queue::Queue(std::string text){
  size = 0;
  front = 0;
  Text = text;
  makeQueue();
  end = size;
   

}

/* this method read the text file and read the length of queue as int and
   read the queuqe parameter as string then convert them to the double 
   and add them to the queue ary*/     
void Queue::makeQueue(){
  std:: string s{};
  int num{};
  // read the lenght and parameter form text file
  std::ifstream ifile{Text};
  if (ifile.is_open())    
    ifile >> length >> s;
  //find the number from string
  for(size_t i{}; i < s.length(); i++){
    if(s[i] == ',')
      num++;
	}
  if(length >= num+1){    
  q = {new double[length]};
  int c{};
  int c1{};
  int count{};
  double toDouble{};
  std::string str{};
  //convert the string number to the double and add them to the array
  for(size_t i{}; i < s.length(); i++){
    if(s[i] == ','){
      c1 = i;
      str = s.substr(c,c1-c);
      toDouble = std::stod(str);
      q[count] = toDouble;
      size++;
      count++;
      c = c1 + 1;
    }
  }
  str = s.substr(c,s.length()-c);
  toDouble = std::stod(str);
  q[count] = toDouble;
  count++;
  size++;
  }
  else
    std::cout << "it not possible creating a Queue" << std::endl;

}
/* show the array and print queue element by element.*/
void Queue::displayQueue(){
  for(int i{}; i < length; i++){
    std::cout << q[i] << '\t';
  }
  std::cout << std::endl;
}
/*if the queue is empty, this method return true*/
bool Queue::isEmpty()
{return size == 0;}
/* add the element x to the queue circularly */
void Queue::enQueue(double x){
  if(size == length)
    std::cout << "the Queue is full" << std::endl;
  else{
    q[end] = x;
    end = (end+1) % length;
    size++;
  }
}
/* delete the queue elemet from first of the queue*/
double Queue::deQueue(){
  if(isEmpty()){
    std::cout << "the Queue is empty" <<std::endl;
    return 0;
  }
  else{
    double inst{q[front]};
    q[front] = 0;
    front = (front+1) % length;
    size--;
    return inst;
  }
}
//destructor of the class
Queue::~Queue(){
  delete[]q;
  
}
