#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
#include<utility>
#include"queue.h"

Queue::Queue( std::string file_name ){
  
  //the counter for lines of data file
  int i{1};
  // temp string that stors a line of data file
  std::string line{};
  // data_file object
  std::ifstream data_file( file_name );

  // check if there is no file with the entered name
  if(!data_file){
    errorPrinter(1);
    isSet = false;
  }
  //the main constractor body
  else if(data_file.is_open()){
    while( std::getline(data_file,line)){
      if(i == 1){
        size = std::stod(line);
	elmnts = new double[size];
	readerPos = writerPos = allocated = 0;
      }
      else if(i == 2){

	auto v = explode( line, ',' );
	isSet = true;
	
	for(int j{}; j<v.size(); j++){
	  enQueue(std::stod( v[j] ));
	}
      }
      i++;
    }
  }

  // error handler
  else {
    errorPrinter(2);
    isSet = false;
  }
}

Queue::Queue() : Queue("") {}

void Queue::displayQueue(void) {
  
  if(isSet) {
    std::cout << std::setw(5) << "key" << std::setw(13) << "value" << std::endl;
    for(int i{}; i<allocated; i++) {
      std::cout << std::setw(4) << realPos(i) << std::setw(13) << elmnts[realPos(i)] << std::endl;
    }
    std::cout << std::endl;
  }
  else
    errorPrinter(3);
}

void Queue::enQueue(double new_elmnt) {
  
  if(isSet){
    if(isFull())
      errorPrinter(4);
    else {
      elmnts[writerPos] = new_elmnt;
      updatePos(false);
      allocated++;
    }
  }
  else {
    errorPrinter(3);
  }

}

double Queue::deQueue(void) {
  
  if(isSet) {
    double tmp{elmnts[readerPos]};
    updatePos(true);
    allocated--;
    return tmp;
  }
  else{
    errorPrinter(3);
    return 0;
  }
}

void Queue::updatePos(bool type) {

  if(type) {
    readerPos++;
    if(readerPos == size)
      readerPos = 0;
  }
  else {
    writerPos++;
    if(writerPos == size)
      writerPos = 0;
  }
}

bool Queue::isFull(void) {
  if( (writerPos == readerPos) && (allocated > 0) )
    return true;
  else
    return false;
}

int Queue::realPos(int i) {
  return (readerPos+i) % size;
}

void Queue::errorPrinter(int eCode) {

  switch(eCode)
    {
    case 1:
      std::cout << "File not found!" << std::endl;
      break;
    case 2:
      std::cout << "There was an error opening the data file" << std::endl;
      break;
    case 3:
      std::cout << "You cannot use this method! becase you initialized the class by wring input or the data file is broken!" << std::endl;
      break;
    case 4:
      std::cout << "The Queue is full! you cannot enter new elements to it!" << std::endl;
      break;
    case 5:
      break;
    default:
      break;
    }
}

std::vector<std::string> Queue::explode(std::string const & s, char delim) {
  
    std::vector<std::string> result;
    std::istringstream iss(s);

    for (std::string token; std::getline(iss, token, delim); )
    {
        result.push_back(std::move(token));
    }

    return result;
}

Queue::~Queue() {
  
  if(isSet)
    delete [] elmnts;
}

