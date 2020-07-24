/*
AP-HW2-Q3
9423054
*/

#include"Queue.h"
#include<fstream>
#include<iomanip>



Queue::Queue(const char* filename) //constructor
  {

    std::ifstream file{filename}; //opens the text file
    
    if (!file) //if there is no file 
      {
	std::cout << "File Not Found" << std::endl;
      }
    
    file >> size; //reading the first number in file
    

    nums = new double[size];  //defining dynamic array 

     for(size_t i{}; i < size; i++) //initializing the array
       nums[i] = 0;
   
    while (1) 
      {  //works untill it reaches the end of file

	file >> nums[write] >> tmp; //gets each number and comma
	
	
	if (file.eof())   break;
	
     	write++; //always points to last added element
	
	 }
    
    file.close(); //closing the file

  }


Queue::Queue() : Queue(" ") {} //default constructor
  
void Queue::displayQueue()    
   {  //this function prints the Queue
  
  std::cout << "Elements of This Queue Are:" << std::endl;
  
  if(read < write)
    {
      for (size_t i{read}; i <= write; i++)
      	std::cout << std::setw(8) <<  nums[i];
    }
  else if (write < read)
    {
      for (size_t i{read}; i < size; i++)
      	std::cout << std::setw(8) <<  nums[i];
      for (size_t i{}; i <= write; i++)
      	std::cout << std::setw(8) <<  nums[i];
    }
      else
	std::cout << "Queue is Empty." ; 
      
    
   std::cout << "\n" << std::endl;
   }



void Queue::enQueue(double num)
   {  //adds number to Queue

     if ((write + 1) % size != read)
       { //works if Queue isnt full
	 
	 write++; //points to empty location
	 write %= size; //circular
	 nums[write] = num;
			 
       }
    
   else
    std::cout<<"Queue is Full! Try Deleting Elements by deQueue()"<< std::endl;
   }



void Queue::enQueue() 
  {   //in case theres no input number
  std::cout << "Value passed to Queue must be valid!" << std::endl;
  }




double Queue::deQueue()
  { //deletes elements in Queue, returns the value of deleted element
    
    if (write != read)
      {
      value = nums[read];
      read++; //always points to first added element
      read %= size;
    }
  
    else
      std::cout << "Queue is Empty!" << std::endl;
        
   return value;
  }

Queue::~Queue()
  {
    delete[] nums;
   }
