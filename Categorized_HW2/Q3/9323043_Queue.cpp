#include<iostream>
#include"Queue.h"
#include <fstream>
#include<string>

Queue::Queue(std::string file) {
  std:: ifstream ifile{file,std::ios::app};
 
   ifile>>N;
   
   std::cout<<"The size of array is :"<<N<<std::endl;
    arr=new double [N];
    
    for(int i{} ;i<N ; i++)  
    {
      
      ifile>>arr[i]>>cama;    //get a double and a cama ',' from the file
      
      
      if(arr[0] ==0)          //for not storing zeros in line 1 into array
	ifile>>arr[i]>>cama;  //get file a gain

      
      if(arr[i] != 0 )
      WritePointer=i+1;
      
      if(WritePointer == N) { //The array is full
	WritePointer=0;       //The array has benn full
       	
      }
                      
    }
      std::cout<<std::endl;
  
 
 ifile.close();
 

}
void Queue::displayQueue(){

  std::cout<<"the numbers in array are : "<<std::endl;

  //find min, max index between ReadPointer and WritePointer for Displaying array
  
  if (ReadPointer >WritePointer){
     minindex = WritePointer ;
     maxindex = ReadPointer ;
  }

  else if (ReadPointer <WritePointer){
     maxindex= WritePointer;
     minindex = ReadPointer;
  }
 
  
  for (int i{minindex} ; i<maxindex ;i++)
   std::cout<<arr[i]<<"  ";
    std::cout<<std::endl;
  }

void Queue:: enQueue(double num){        //Writing in array
   if (WritePointer == ReadPointer)
  
    std::cout<<"The array is full.can not writing the element you want"<<std::endl;
  else{
    arr[WritePointer]=num;
    WritePointer++;
    
    
    if(WritePointer == N)  //end of array
	WritePointer=0;
    
    
        }
}
  


double Queue::deQueue(){       //read the first input in array

           
  double deletevalue{arr[ReadPointer]};
  
  if (deletevalue == 0)  //means array has been empty
    {
      std::cout<<"array is empty"<<std::endl;
      deletevalue = 0;
     
    }
  ReadPointer ++;
  if(ReadPointer == N)
    ReadPointer = 0;
  return deletevalue;

  }
  

Queue::~Queue(){

  std::cout<<"Distructor"<<std::endl;
  delete [] arr;
  
}
