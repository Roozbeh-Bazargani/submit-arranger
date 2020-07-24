#include"Queue.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

Queue::Queue (std::string txt){
 this -> txt= txt;
 rear = front = -1;
 std::vector < std::string > v;
 std::ifstream myfile("Queue.txt");
 while( myfile >> str)
  {
    v.push_back(str); 
  }
  myfile.close();
  
std::string s = v[1];//receive the elements of array in form of string
 int N = std::atof(v[0].c_str()), i{};//N is the size of array
arr = new double[N]; // declaring array containing numbers
std::string delimiter = ",";
//defining a string for breaking while the program receive','
size_t pos = 0;
std::string token;
std::cout << "extracted numbers from text: " << std::endl;
while ((pos = s.find(delimiter)) != std::string::npos) 
{
  //in this part elements string will be seperated by using comma
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    arr[i] = std::atof(token.c_str());
    i++;
    s.erase(0, pos + delimiter.length());
}
 std::cout << s << std::endl;
 arr[i] = std::atof(s.c_str());// change type of elements to save them in array
std::cout << "\nvalues of array: " << std::endl;
for(int j{}; j<7; j++)
{
  std::cout << arr[j] << std::endl;
}
// in this part we should determine the amounts of rear and front by checking array's elements
  if(arr[0]!= 0){
    front= 0;
     for(int j{}; j<7; j++){
	if(arr[j] != 0)
	      rear++;
	 }
    }
}

 void Queue::displayQueue(){
 // Display elements present in Circular Queue
   if( front==-1 )
     {
     std::cout << "\n Queue is empty" << std::endl;
     }
   std::cout << "array elements are as follows" << std::endl;
   if( rear >= front)
     // when rear is lagrer or equal to front there is no need to change the queue and we should just type it as usual
     {
     for (int i{front} ; i <= rear ; i++)
       std::cout << arr[i] << std::endl;
     }
   else
     // in this condition elements are rotated so we should display two seperate part one ofter the other.
     {
     for (int i{front} ; i < N ; i++)
       std::cout << arr[i] << std::endl;
     for(int i{} ; i <=rear ; i++)
       std::cout << arr[i] << std::endl;
     }
 }

void Queue::enQueue(double val){
   // Inserting elements in Circular Queue
if ((front == 0 && rear == N-1) ||(rear == front-1))
  // thi sif check the array for the full condition 
  {
  std::cout <<"\nQueue is Full" << std::endl;
  }
else
  if (front == -1){
 //if the array was not full by changing the amout of rear and front we should put the element in array. 
    front = rear = 0;
    arr[rear] = val;}
  else
     if(rear == N-1 && front != 0){
       rear = 0;
       arr[rear] = val;
     }

     else {
       rear++;
 arr[rear] = val;
}
}
 // Deleting elements from Circular Queue    
double Queue::deQueue(){
  if (front == -1){
    // in this condition there are no elements for being deleted by enqueue.
    std::cout <<"\nQueue is Empty" <<std::endl;}
  double deleted = arr[front];//the candidate element for being deleted in front elemet.
  arr[front] = -1;// after deleting we should change front to -1
  if (front == rear){
     front = rear = -1;
     }
  else{
    if (front == N-1)
       front = 0;
    else
      front++;}

return deleted;
}

