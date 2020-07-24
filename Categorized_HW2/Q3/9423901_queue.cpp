#include"queue.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>


Queue::Queue(const char* txtname) {
  //std::cout << "Constructor" << std::endl;
  std::ifstream inFile {txtname}; // Create input stream object
  // Make sure the file stream is good
  if (!inFile)
    {
      std::cout << "Failed to open file " << txtname << std::endl;
      //return 1;
    }
  
  inFile >> length; //reading length
  std::cout << "length of queue = " << length << std::endl;
  elements = new double[length];
  
  while(true){ //reading numbers as string
    inFile >> temp;
    if (inFile.eof())
      break;
  }


  for(size_t i{}; i < temp.length() ; i++){ //extracting numbers
    if(temp[i] == ','){
      end = i;
      elements[number++] = std::stod(temp.substr(start,(end - start)));
      start = end + 1;
    }
    else if (i == (temp.length() - 1)) //extracting last number after comma
      elements[number++] = std::stod(temp.substr(start,(temp.length() - start)));
  }
  Rposition = 0; // pointer for deleting , points to first element
  Wposition = number; //pointer for entering , ponints to first empty element from last
  inFile.close(); // Close the input stream
}

void Queue::displayQueue() {
  for(size_t i{}; i < length; i++)
    std::cout << elements[i] << " ";
  std::cout << std::endl;
}

void Queue::enQueue(double newmem) {
  if((Wposition < length) && (Wposition != Rposition))
    elements[Wposition++] = newmem;
  else if((Wposition == length) && (Rposition != 0)){
    Wposition = 0;
    elements[Wposition++] = newmem;
  }
  else if(((Wposition == Rposition) && ((elements[Wposition-1] != 0) && (elements[Wposition+1] != 0)))
     || ((Wposition == length) && (Rposition == 0))){
    std::cout << "Queue is full !" << std::endl;
    std::cout << Wposition << " " << Rposition << std::endl;
  }
  else
    elements[Wposition] = elements[Wposition];
}

double Queue::deQueue() {
  if((Rposition < length) && (Wposition != Rposition)){
    tempout = elements[Rposition];
    elements[Rposition++] = 0;
    return tempout;
  }
  else if((Wposition == Rposition) && ((elements[Rposition-1] == 0) && (elements[Rposition+1] == 0))){
    std::cout << "Queue is empty !" << std::endl;
    Wposition = 0;
    Rposition = 0;
    return 0;
  }
  else if(Rposition == length){
    tempout = elements[Rposition];
    elements[Rposition] = 0;
    Rposition = 0;
    return tempout;
  }
  else
    return 0;
}

Queue::~Queue(){
  // std::cout << "Distructor" << std::endl;
  delete[] elements;
}
