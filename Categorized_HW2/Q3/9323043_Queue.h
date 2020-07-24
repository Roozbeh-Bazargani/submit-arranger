#include<fstream>
#include<string>

class Queue {

 public:
  

  Queue (std::string file);    //constructor
  
  ~Queue();                        //Distructor

  void displayQueue ();
  void enQueue( double num);      //Inserting in array
  double deQueue();               //deleting from array
  


 private:
  int N;
  double num;                    //for Insert a number in array
  double* arr;
  char cama;    //,
  int ReadPointer{};
  int WritePointer{};
  int minindex;                 //for Display function
  int maxindex;                 //for Display function
  std::ifstream ifile;
 

};
