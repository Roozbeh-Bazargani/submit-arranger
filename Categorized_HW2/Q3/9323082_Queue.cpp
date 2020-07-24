#include"Queue.h"
#include<iostream>
#include<string>
#include<fstream>

Queue::Queue(std::string text){
  firstFull = 0;
  queueLength = 0;
  numofElem = 0;
  std::string s{};
  unsigned final{};
  unsigned init{};
  double number{};
  std::string getString;
  //reding the file .txt
  std::ifstream file{text};
  //enter the length of the queue into the int and value of the queue into the s
  file >> queueLength >> s;
  //define the  dynamic array with the length which read from the file
  arrayofNumber = {new double[queueLength]};
  for(unsigned k{}; k < s.length(); k++){
    //check if we read the , from the file
      if(s[k] == ','){
	final = k;
	//read from , to ,
	getString = s.substr(init,final-init);	
	init = final + 1;
	// convert string of value to double
	number = std::stod(getString);
	//creat array of the value of queue
	arrayofNumber[numofElem] = number;
	numofElem++;
       }
    
   }
  // for the last value which does not have , at the end
    getString = s.substr(init , s.length() - init);
    number = std::stod(getString);
    arrayofNumber[numofElem] = number;
    numofElem++;
    lastEmpty = numofElem;
  
}
//declare the function that add to end of queue
void Queue::enQueue(double add){
  //check if the queue is full
  if(numofElem == queueLength)
    std::cout << "the Queue is full. "<< std::endl;
  else{
    //add to end of the queue
    arrayofNumber[lastEmpty] = add;
    lastEmpty = (lastEmpty + 1) % queueLength ;
    numofElem++;
    
  }
}
//declare the function that delete from start of queue
double Queue::deQueue(){
  // check if the queue is empry or not
  if(numofElem == 0){
    std::cout << "the queue is empty. " << std::endl;
    return 0;}
  else{
    //delete from start of the queue
    double trash{arrayofNumber[firstFull]};
    arrayofNumber[firstFull] = 0 ;
    firstFull = (firstFull + 1) % queueLength ;
    numofElem--;
    return trash;}
    
  
}
//distructor that delet the dynamic array
Queue::~Queue(){
  delete[]arrayofNumber;
}
//display the queue
void Queue::displayQueue(){
  std::cout << "queque is: " << std::endl;
  for(int p{}; p < queueLength; p++){
    std::cout << arrayofNumber[p] << '\t' ;
  }
  std::cout << std::endl;
    
   
}
