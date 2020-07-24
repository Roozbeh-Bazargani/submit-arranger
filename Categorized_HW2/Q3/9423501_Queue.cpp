#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// constructor

Queue::Queue(std::string file) {
   this-> file = file;
   std::ifstream ifile( file );
   while (!ifile)
     std::cout << " File can not open! " << std::endl;
}

// displayQueue function

void Queue::displayQueue(){
  std::ifstream ifile( file );
  while (ifile >> temp)
     {
       ifile >> ch ;
       std::cout << temp << std::endl; // read the file
       if ( i == 0 )
	 count = temp ;     // number of elements
       else if ( i != 0 )
	 arr[i] =  temp ;
       i++ ;
     }
  n = i ;
  read = &arr[1];
  write = &arr[n];
}

// enQueue function

void Queue::enQueue (double a){
  for ( int i{1}; i < count+1 ; i++ )
    {
      if ( arr[i+1] != 0 )
	read ++ ;
      else 
	{
	  std::cout << "please enter number:";
	  std::cin >> a ;
	  arr[i] = a ;
	}
    }
  for ( int i{1}; i < count; i++ )
    std::cout << arr[i] << std::setw(10) ;
  std::cout << std::endl;
  std::cout << "calling deQueue function: " << std::endl;
}

// deQueue function

double Queue::deQueue (){
  if ( read != &arr[n] )
    arr[n] = 0 ;
   for ( int i{1}; i < count; i++ )
    std::cout << arr[i] << std::setw(10) ;
  std::cout << std::endl;
}


