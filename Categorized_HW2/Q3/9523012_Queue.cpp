#include "Queue.h"


Queue::Queue(const std::string &s)
{
  std::ifstream myfile(s); //reading file
  if (myfile.is_open()) // Checking file
    {
      // Reading numbers
      char ch{};
      myfile >> N;
      p = new double[N];
      while (myfile >> p[cnt++]) // Storing numbers
	{
	  myfile >> ch;
	}
      cnt--;
    }
  else
    std::cout << "Couldn't read the file!\n";
  myfile.close();
}

Queue::~Queue()
{
  delete[] p; //deleting dynamic pointer
}

void Queue::displayQueue() // display numbers
{
  for (size_t i{}; i < cnt; i++)
    {
      std::cout << p[(tail + i) % N] << " ";
    }
  std::cout << "\n";
}

void Queue::enQueue(double d)
{
  if (cnt == N) //Is Queue full?
    std::cout << "Error: Queue is full\n";
  else // Inserting element
    {
      p[(tail + cnt) % N] = d;
      cnt++;
    }
}

std::string Queue::deQueue()
{
  if (cnt==0) //Is Queue empty?
    return "Queue is empty";
  else // Deleting element and return it for cout
    {
      cnt--;
      std::ostringstream ss{};
      ss << p[(tail++) % N];
	  tail %= N;
      return ss.str();
    }
}
