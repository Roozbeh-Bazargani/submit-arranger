//Created By Mohammad Sadegh Safari 9323046

#include"queue.h"
#include<fstream>
#include<iostream>
#include<string>

//Defining Class Constructor
Queue::Queue(const char* a) {
  std::cout <<"constructor"<<std::endl;

  //Defining an ifstraem object for reading from file
  std::ifstream ifile{a};

  //check file existance
  if(!ifile) {
    std::cout << "file not found" << std::endl;
  }
  else {
    std::string firstline{},valueline{};

    //reading size of Queue
    std::getline(ifile,firstline);
    this->size = std::stoi(firstline);
    std::cout<<"size"<<size<<std::endl;

    //reading lin contains queue variables and close file
    std::getline(ifile,valueline,'\r');
    ifile.close();

    //defining a dynaminc array for storing queue variables
    values = new double[this->size];
    
    size_t start{}, end{};
    size_t i{1};

    //reading queue values and store them
    while(start<valueline.size()) {
      end = valueline.find_first_of(",",start);

      //check for end of line
      if(end == std::string::npos) {
	end = valueline.size();
      }

      //store value and increase writeposition
      values[i] = std::stod(valueline.substr(start,end - start));
      std::cout << "value" << i << values[i] << std::endl;
      this->writeposition = (this->writeposition+1)%this->size;

      //check for end of queue
      if(i == 0) {
	full = true;
	break;
      }
      
      start = end + 1;
      
      if(++i == this->size) {
	i = 0;
      }
      
    }
    
  }
  
}


//Defining Class Destructor
Queue::~Queue(){
  delete[] values;
}


//Defining Method for Displaying Queue
void Queue::displayQueue() const {

  //check queue is empty or not
  if( readposition == writeposition && !full) {
    std::cout << "Queue is empty!!!" << std::endl;
  }
  else {
    size_t i{(this->readposition+1)%this->size};
    std::cout << "Queue is:" << std::endl;

    //Display queue values
    while (i%this->size != this->writeposition) {
      std::cout << values[i%this->size] << std::endl;
      i++;
    }

    //display end of queue
    std::cout << values[i%this->size] << std::endl;
  }
  
}


//Defining Method for inserting in Queue
void Queue::enQueue(double newvalue) {

  //check that queue isn't full
  if(!this->full) {
    this->writeposition = (this->writeposition+1)%this->size;
    this->values[this->writeposition] = newvalue;

    //check that queue is full now or no
    if((this->writeposition)%this->size == this->readposition) {
    full = true;
    }
    
  }
  else {
    std::cout << "Queue is full!!!" << std::endl;
  }
  
}


//Defining Method for Delete from Queue
double Queue::deQueue() {

  //check that queue is emty or no
  if(!full && this->readposition == this->writeposition) {
    std::cout << "Queue is empty and you can not delete anything!!!!" << std::endl;
    return 0;
  }
  //Delete from queue if it is not empty
  else {
    this->readposition = (this->readposition+1)%this->size;
    full = false;
    
    return this->values[this->readposition];
  }
    
}
  
