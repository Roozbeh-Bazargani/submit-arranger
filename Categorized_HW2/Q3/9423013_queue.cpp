#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"queue.h"

std::string convert(double);  //  For displaying the result of deQueue()

//  Constructor
Queue::Queue(std::string s){ 
  std::ifstream file{s};
  file>>n;
  p=new double[n];
  p_start=p;
  p_end=p;
  p_current=p;
  double temp_element{};
  char temp_char;
  while(true){ 
    file>>temp_element;
    file>>temp_char;
    enQueue(temp_element);
    if(file.eof())break;
  }
}

//  For adding to the queue
void Queue::enQueue(double x){
  if(distance()<n-1){
    p_end=p_current;
    *p_current=x;
    inc(p_current);
    isEmpty=false;
  }
  else{
    std::cout<<"You can't add anything to a full queue!\n"<<std::endl;
    }
  
}

//  For removing from the queue
std::string Queue::deQueue(){
  std::string temp;
  if(distance()!=0){
    temp=convert((*p_start));
    inc(p_start);
  }
  else{
    if(isEmpty){
      temp="Nothing (You can't delete anything from an empty queue!) \n";
    }
    else{
      isEmpty=true;
      temp=convert((*p_start));
    }
  }
  return temp;
}

//  For displaying the queue
void Queue::displayQueue(){
  if(!isEmpty){
    if(p_end>=p_start){
      for(double* i{p_start}; i<=p_end; i++)
	std::cout<<*i<<"\t";
    }
    else
      {
	for(double* i{p_start};i<p+n;i++)
	  std::cout<<*i<<std::endl;
	for(double* i{p};i<=p_end;i++)
	  std::cout<<*i<<std::endl;
      }
    std::cout<<"\n\n";
    
  }
  else{
    std::cout<<"The Queue is Empty! \n\n";
  }
}

//  For measuring the distance between p_start and p_end
size_t Queue::distance(){
  if (p_end>=p_start) {
      return p_end-p_start;
  }
  else
    {
      return (p+n-1)-(p_start)+(p_end-p)+1;
    }
}

//  for moving to the next element of the queue
void Queue::inc(double*& var){
  if (var==p+n-1){
    var=p;
  }
  else
    {
      var++;
    }
}

std::string convert(double x){
  std::string temp;
  std::ostringstream strs;
  strs<<x;
  temp=strs.str();
  return temp;
}

