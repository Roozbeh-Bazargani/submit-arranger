#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include"Queue.h"

using std::string;

Queue::Queue(string Qtxt){
  std::ifstream txtFile (Qtxt); //Gets the input file Queue.txt in txtFile
  char separator{}; // character for saving the space between numbers
  double InNum{}; //input number to be saved in queue
  txtFile >> Qlength; //first number of Queue.txt is queue length
  txtFile >> separator; //then there is a \n after the length
  double* cirQueue{new double[Qlength]}; //make room for the queue
  Readptr = Writeptr = &(cirQueue[0]); //at the start bot read and write pointer are the first of the array
  while ( !txtFile.eof() ){ //until the end of file
    txtFile >> InNum; //get the numbers
    txtFile >> separator; // and space between them
    enQueue(InNum); //call enQueue function to save the number in queue
  }
}

void Queue::displayQueue(){
    double* disptr{Readptr};
    if (disptr < Writeptr){ //if the read pointer is before the write pointer we
      //should go forward to read the queue members
      std::cout<< "Circular Queue's Elements are:\n";
      while (disptr != Writeptr){
      std::cout << *disptr++ <<"\t";
      }
      std::cout << std::endl;
    }
    else if (disptr > Writeptr){ //if the read pointer is after the write
      //pointer, we should go to the end and then read from begining to writeptr
      std::cout<< "Circular Queue's Elements are:\n";
      for(; disptr <= (cirQueue+Qlength); disptr++){
	std::cout << *disptr <<"\t";
      }
      for(disptr = cirQueue; disptr < Writeptr; disptr++){
	std::cout << *disptr <<"\t";
      }
      std::cout << std::endl;
    }
    else{ //if the read pointer and the write pointer are the same then
      //either queue is empty or full
      if(elementNum == 0) // check if queue is empty
	std::cout<< "Circular Queue is empty.\n";
      else{ //if it's not empty it's full
	std::cout<< "Circular Queue is full. The Elements are:\n";
      for(; disptr <= (cirQueue+Qlength); disptr++){
	std::cout << *disptr <<"\t";
      }
      for(disptr = cirQueue; disptr < Writeptr; disptr++){
	std::cout << *disptr <<"\t";
      }
      std::cout << std::endl;
      }
    }
}

void Queue::enQueue(double in){
  if (elementNum == Qlength) //if elementNum is equal to length the queue is
    //empty and we can't write on it
    std::cout << "Circular Queue is full.\n";
  else{
    *Writeptr = in;
    elementNum++;
    if (Writeptr == (cirQueue+Qlength))
      Writeptr = cirQueue;
    else
      Writeptr++;
  }
}

double Queue::deQueue(){
  if (elementNum != 0){
    double out{*Readptr};
    elementNum--;
    if (Readptr == (cirQueue+Qlength))
      Readptr = cirQueue;
    else
      Readptr++;
    return out;
  }
  else{
    std::cout << "Warning! Circular Queue is empty.\n";
    return '\0';
  }
}

Queue::~Queue(){
  delete[] cirQueue;
}
