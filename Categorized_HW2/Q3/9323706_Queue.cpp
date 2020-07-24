#include"Queue.h"


Queue::Queue(const char* queName) : N{0} {
  size_t j{1};
  char ch;
  while(queName[N++]);
  this->queName = new char[N];
  for(size_t i{0}; i<N; i++)
    this->queName[i]=queName[i];
  std::ifstream ifile{queName};
  ifile >> lenQue;
  rpointer = 0;
  queArr = new double[lenQue];
  ifile >> *(queArr);
  while(!ifile.eof()){
    ifile >> ch;
    ifile >> *(queArr+j);
    j++;
  }
  wpointer=j;
  ifile.close();
}

void Queue::displayQueue() {
  for(size_t i{0}; i<lenQue; i++)
    std::cout << *(queArr+i) << ',';
  std::cout << std::endl;  
}


void Queue::enQueue(const double a) {
  if(wpointer>(lenQue-1)){
    if(rpointer==0){
      std::cout << "fail to insert: " << a << " -> the Queue is full " << std::endl;
    }
    else{
      wpointer = 0 ;
    };
  };
  queArr[wpointer] = a;
  wpointer++;
}

double Queue::deQueue() {
  double a;
  if(rpointer>(lenQue-1)){
    if(wpointer==0){
      std::cout << "the Queue is empty" << wpointer << std::endl;
    }
    else{
      rpointer = 0 ;
    };
  };
  a = queArr[rpointer] ;
  queArr[rpointer] = 0 ;
  rpointer++;
  return a;
}

Queue::~Queue() {
  
  remove(queName);
  std::ofstream ofile{queName};
  ofile << lenQue << '\n';
  std::ostringstream oss{};
  for(size_t i{0}; i<(lenQue); i++){
    size_t j = i + rpointer;
    if((j%lenQue)>=rpointer || (j%lenQue)<wpointer){
      oss << *(queArr+(j%(lenQue))) ;
      if(i<(lenQue-1))
	oss << ',';
    }
  }
  std::string s{oss.str()};
  s.erase(s.length());
  ofile << s;
  ofile.close();
  
  delete[] queName;
  delete[] queArr;
}
