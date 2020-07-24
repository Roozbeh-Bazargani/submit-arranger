#include "Queue.h"


Queue::Queue(std::string a) {			// i take 0 as the cell is empty!
  std::ifstream file;
  file.open(a);
  file >> N;
  char _t{};
  size_t i{};
  Nums = new double[N];
  e = 0;
  while (file >> Nums[i++])
    {
      file >> _t;
    }
  d = i - 1;
  for (size_t j{ i - 1 }; j < N; j++)
    {
      Nums[j] = 0;
    }

}

void Queue::displayQueue()
{
  for (size_t i{}; i < N; i++)
    std::cout << Nums[i] << "\t";
  std::cout << std::endl;
}

void Queue::enQueue(double a)
{
  if (d >= N)
    handle_d();
  if (d < N) {
    if (Nums[d] == 0)
      Nums[d++] = a;
    else
      std::cout << "Queue is full" << std::endl;
  }

}

double Queue::deQueue()
{
  double temp{};
  if (e >= N)
    handle_e();
  if (Nums[e] != 0) {
    temp = Nums[e];
    Nums[e++] = 0;
  }
  else
    {
      std::cout << "nothing exist to delete" << std::endl;
      temp = 0;
    }
  return temp;
}

void Queue::handle_d()
{
  d %= N;
}

void Queue::handle_e()
{
  e %= N;
}
