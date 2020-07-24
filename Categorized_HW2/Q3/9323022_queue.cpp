#include"queue.h"
#include<fstream>

using std::cout;
using std::endl;

Queue::Queue(std::string address)
{
  std::ifstream inputFile{address}; //get address from input and open file
  float plate{0};
  char waste;
  inputFile >> this->queue_size; //read queue size
  size_t i{0};
  for(i=0; (i<this->queue_size) && (!inputFile.eof()); i++)
    {
      inputFile >> plate; //read number
      inputFile >> waste; //read , between numbers!
      this->queue_members[i] = plate;
    }
  if (i == this->queue_size) //equeue filled from file data
    {
      i = 0;
      full = true;
    }
  this->queue_last_index = i; 
  this->queue_first_index = 0;
}

void Queue::displayQueue()
{
  if (this->queue_first_index < this->queue_last_index) 
    {
      cout << "queue members: ";
      for (size_t i{this->queue_first_index}; i<this->queue_last_index; i++)
	cout << queue_members[i] << " ";
    }
  else if ((this->queue_first_index > this->queue_last_index) || ((this->queue_first_index == this->queue_last_index) && (full)))
    {
      cout << "queue members: ";
      for (size_t i{this->queue_first_index}; i<this->queue_size; i++)
	cout << queue_members[i] << " ";
      for (size_t i{0}; i<this->queue_last_index; i++)
	cout << this->queue_members[i] << " ";
    }
  else
    cout << "queue is empty!";
  cout << endl;
}

void Queue::enQueue(float input)
{
  if ((this->queue_last_index == this->queue_first_index) && (full))
    {
      cout << "buffer is full! you can't add new member.\n";
      return;
    }
  this->queue_members[queue_last_index] = input;
  this->queue_last_index++;
  if (this->queue_last_index == queue_size)
    this->queue_last_index = 0;
  if (this->queue_last_index == this->queue_first_index)
    full = true;
}

float Queue::deQueue()
{
  if ((this->queue_last_index == this->queue_first_index) && (!full))
    {
      cout << "buffer is empty! you can't delet any memeber.\n";
      return 0;
    }
  float plate = this->queue_members[this->queue_first_index];//member it and return at then end of function
  this->queue_first_index++;
  if(this->queue_first_index == this->queue_size)//turn circule!
      this->queue_first_index = 0;
  if (this->queue_last_index == this->queue_first_index)
    full = false; 
  return plate;
}
