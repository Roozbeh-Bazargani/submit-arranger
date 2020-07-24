#include"Queue.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>
#include<vector>

Queue::Queue(std::string name){
  
  std::ifstream text;
  text.open(name);
  std::string line;
  getline(text ,line);
  std::stringstream geek(line); //convert string to int or size_t?
  geek >> N;
  arr=new double[N];
  read=arr;
  write=arr;

  std::vector<std::string>words;
  
  while(getline(text , line))
    {
	  const std::string separators{" ,;:\"!?'\n()"};
	  size_t start { line.find_first_not_of(separators) };
	  size_t end{};
 
	  while (start !=std::string::npos)     // Find the numbers
	    {
	      end = line.find_first_of(separators, start + 1); 
	      if (end == std::string::npos)// Found a separator?
		{
		  end = line.length();// No, so set to last + 1
		}
	           
	      words.push_back(line.substr(start, end - start));
	       // Find 1st character of next word
	      start = line.find_first_not_of(separators, end + 1);
	      }
    }
 
 for(size_t i{}; i < words.size() ; i++)
   {
     arr[i] = atof(words[i].c_str()); //convert string to double
   }
 
 write=write+words.size();     

}

void Queue::displayQueue(void){
  
  if(read < write)
    {
      size_t temp=write-read;
      for(size_t i{} ; i < temp ; i++)
	{
	  std::cout << *(read+i) <<"   ";
     
	}
    }
  else if(read==write)
    {
      if(flag_empty)
	std::cout<< " There is nothing in your Queue"<<std::endl;
      else if(flag_full)
	{
	  size_t temp=write-read;
	  for(size_t i{temp} ; i < N ; i++)
	    {
	      std::cout << arr[i] <<"  " ;
	    }
	  for(size_t i{} ; i < temp ;i++)
	    {
	      std::cout << arr[i] <<"  ";
	    }
	}
    }
  else
    {
      size_t temp1=read -arr;
      size_t temp2=write-arr;
       for(size_t i{temp1} ; i < N ; i++)
	 {
	   std::cout << arr[i] <<"  " ;
	 }
       for(size_t i{} ; i < temp2 ;i++)
	 {
	    std::cout << arr[i] <<"  ";
	 }
    }
  std::cout<<std::endl;

}


void Queue::enQueue(double num){

  std::cout <<"insert: "<< num << std::endl;
    if(write==read && !flag_empty)
    {
      flag_full=true;
      std::cout << "Your Queue is Full" <<std::endl;
    }
    else
      {
	 flag_empty=false;
	*(write)=num;
	 
  if(write > arr+5)
    {
      write=arr;
    }
  else
    {
      write=write+1;
    }
      }
}

double Queue::deQueue(void){
   if(read==write && !flag_full)
     {
       std::cout<<"Your Queue is empty"<< std::endl;
       flag_empty = true;
       return 0;
     }
   else
     {
       double temp=*(read);
       flag_full=false;
       if ( read > arr+5)
	 read=arr;
    
       else
	 read=read+1;
       return temp;
     }
}

Queue::~Queue(){
  
   delete[]arr;
}
