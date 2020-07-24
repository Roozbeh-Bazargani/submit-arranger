#include"Queue.h"

Queue::Queue(std::string str){
  std::ifstream ifile{str};
  ifile >> N;
  top = 0;
  bottom = 0;
  intermediate = 0;
  double temp;
  number = new double[N];
  char a;
  while(true)
    {
      if(ifile.eof())break;
      ifile >> temp;
      enQueue(temp);
      ifile >> a;
    }
  isFull = false;
}

void Queue::enQueue(double num){
  isFull = true;
  intermediate = top;
  top++;
  if(intermediate > 6){
    top= 0;
    if(top == bottom){
      top = intermediate;
      intermediate--;
      std::cout << "Queue is Full :(" << std::endl;
    }
    else{
      intermediate = 0;
      top = 1;
      number[0] = num;
    }
  }
  
  else if(intermediate == bottom){
    if(intermediate != 0){
      std::cout << "Queue is Full :( " << std::endl;
      top = intermediate;
    }
    else
      number[intermediate] = num;
  }

  else
    number[intermediate] = num;
    
}

double Queue::deQueue(){
  size_t m = bottom;
  bottom++;
  if(bottom >= N)
    bottom =  0;
  if(bottom == intermediate){
    std::cout << "Queue is empty :( " << std::endl;
    isFull = false;
    bottom--;
  }
  isFull = true;
  return number[m];
}

void Queue::displayQueue(){
  if(isFull == true){
    std::cout << "numbers in Queue are : " << std::endl;
    if(intermediate>bottom)
      for(size_t i{bottom}; i<=intermediate; i++)
	std::cout << number[i] << std::endl;
    if(intermediate<bottom){
      for(size_t i{bottom}; i<N; i++)
	std::cout << number[i] << std::endl;
      for(size_t i{}; i<=intermediate; i++)
	std::cout << number[i] << std::endl;
    }
     if(intermediate>bottom && intermediate==N)
      for(size_t i{bottom}; i<intermediate; i++)
	std::cout << number[i] << std::endl;
     if(intermediate==bottom){
      for(size_t i{bottom}; i<N; i++)
	std::cout << number[i] << std::endl;
      for(size_t i{}; i<intermediate; i++)
	std::cout << number[i] << std::endl;
     }
  }
  else
    std::cout << "Queue is empty :(" << std::endl;
}

Queue::~Queue(){
  delete[] number;
}
