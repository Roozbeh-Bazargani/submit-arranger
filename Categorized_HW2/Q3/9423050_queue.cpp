#include "queue.h"
#include <sstream>
#include <fstream>
#include <stdlib.h>

Queue::Queue(const char* inp){
  std::ifstream inFile{inp};//input stream
  inFile >> N; // size of Queue
  std::string temp{};
  while(true){ // second line
    inFile >> temp; 
    if (inFile.eof())
      break;
  }
  Ptr = new double[N]; // Queue with N elements
  size_t siz{};
  std::string tmp; 
  size_t a{};
  while( siz < temp.length()){ // reading the inputs
    tmp.clear();
    a = siz;
    while( temp[siz] != ',' ) // seperating each input
      {
	siz++;
      }
    tmp.append(temp,a,(siz-a)); // appending to a temporary string
    Ptr[M] = std::stod(tmp.substr(0,tmp.length())); // string to double coverter
     M++;
    siz++;
  }
  inFile.close(); // close the input
    K = 0;
    if( M == 0 ) // empty or not checker
      E = 1;
    else
      E = 0;

    if( M == N) // full or not checker
      F = 1;
    else
      F = 0;

}

Queue::~Queue(){ // Destructor
  delete[] Ptr;
}

void Queue::displayQueue(){
  if( E == 1 ){ // when empty
    std::cout<<"Queue is empty !"<<std::endl;
  }
    else{
      std::cout<<"Queue Members : "<<std::endl;
      if( M > K){
	 for(size_t i{K}; i<M; i++)
	   std::cout<<Ptr[i]<<" ";
         }
      else{ // when overlap occurs
	for(size_t i{K}; i < N ;i++)
	  std::cout<<Ptr[i]<<" ";
	for(size_t i{}; i < M ;i++)
	   std::cout<<Ptr[i]<<" ";
      }
      std::cout<<std::endl;
    }
}

void Queue::enQueue(double input){
  if( F == 1 ) // full checker
    std::cout<<"Operation Failed! Queue is full."<<std::endl;
  else{
    Ptr[M] = input;
    M++;
    if( M == N )
      M = 0;
    if( M == K )
      F = 1;
    E = 0;
    std::cout<<input<<" added to the Queue."<<std::endl;
  }
}

std::string Queue::deQueue(){
  if( E == 1 ){ //empty
    std::string str{"Deleting Failed! Queue is empty"};
    return str;
  }
  else
    {
      double temp{Ptr[K]};
      K++;
      if( K == N )
	K = 0;
      if( K == M)
	E = 1;
      F = 0;
      
      std::ostringstream strs;  // string to double converter
      strs << temp;
      std::string str = strs.str();
      return str;
    }
}
