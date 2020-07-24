#include"Queue.h"
Queue::Queue(std::string str){// costructor
  std::ifstream ifile(str); //get size and array
  ifile>>n;
  arr = new double[n];
  for(int i{};i<n;i++){
    ifile>>arr[i]>>m;
    if(arr[i]==0){
      w=i++ ; // show the last array 
      break;}
   
  }
  ifile.close(); //close the file
}
void Queue::displayQueue(){// just show the value of array
  for(int i{};i<n;i++){
    std::cout<<arr[i]<<"  ";
  }
  std::cout<<std::endl;
}

void Queue::enQueue(double a){ //we can add new value on array
  if(w==n){
    std::cout<<"array is full"<<std::endl;
    r=0;}
  else{
    arr[w]=a;
    w++;}
}
double Queue::deQueue(){ // show the value then delete it.
  f= arr[r];
  arr[r]=0;
  r++;
  
  return f;
}
    
Queue::~Queue(){ //discostructor

   delete []arr;
  std::cout<<" delete all array "<<std::endl;
}
