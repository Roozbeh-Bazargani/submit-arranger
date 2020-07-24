#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"Queue.h"
#include<iomanip>

Queue::Queue(std::string f)
{
  filename = f;
  std::ifstream file(f,std::ios_base::in);//opening file
  
  if(file.is_open())
    {
      file>>size;//size of array
       for(int i{};i<size;i++)
	 {
	  v.push_back(0);
	     
	 }
     
       while(file>>tmp)//reading file
	{
	  v[index]=tmp;
	  file>>ch;//leaving commas
	 index++;
	}
     
       write= &v [index];  //place of write pointer
       read=& v[0];  //place of read pointer
       if(write>read)   //defining distance
	 distance=write -read;
       else
       distance=read-write;
    }
 
}


void Queue::displayQueue()
{
  if(write>read) //printing when write>read
  {
  
    take=read;//saving read value
    for(int i{};i<distance;i++)//print character by moving read pointer
      {
      	std::cout<<std::setw(10)<<*(read)<<std::endl;
	read++;	

      }
    read=take;//taking its value back
     distance=read-write;
     
    	std::cout<<std::endl;
   
    
  }
  if(write<read)//printing when write<read
      {
	for(int i{};i<size;i++)
		   {
		     float* p{&v[i]};
	    
		     if(!(write<p && p<read))//printing numbers out of
		                             //their distanc
		   
		        std::cout<<v[i]<<"total"<<std::endl;
		      }
	       }
  	  
  if(write==read)//when write & read are pointing to the same place
   {
     distance=0;
     std::cout<<"empty"<<std::endl;
   }
 
      }

void Queue::enQueue(float num)

{

 
  if(write !=(&v[size-1])&& read !=write)//write is not at the end of array
                                         //and read !=write
     {
     
	      newnum=num;
	      *(write)=num;
	     
	     
	      // std::cout<<*(write)<<"      enQueued!!"<<std::endl;
	      write++;
	      if(write>read)          //defining distance
		
		  distance=write -read;
	       
	      else
		distance=read-write;
	      
	        }
  

   else
     {
  newnum=num;
	   (*(write))=num;
	  
	   write=&v[0];
	    //configing distance
    if(write>read)
	 distance=write -read;
       else
       distance=read-write;


     }
   
}

float Queue::deQueue()
{

   if(read==write)
     { //everything is
           //deleted
       flag=1;
    if(write>read)
	 distance=write -read;
       else
	 distance=read-write;}
   else
     {
  float* dlt=read;
  read++;
   if(write>read)
	 distance=write -read;
       else
       distance=read-write;
 
    return (*dlt);
   
	
     }
   
}
