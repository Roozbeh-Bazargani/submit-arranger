#include "func.h"

void show_Nums(std::vector<double> Nums)
{
  for (size_t i{}; i < Nums.size() ; i++)
    {
      std::cout << Nums[i] << "\t";
    }
  std::cout << std::endl;
}

std::vector<double> getNums()
{
  std::vector<double> Nums;
  double temp{};
  while (std::cin >> temp)
    {
      if (temp == 0)
	break;
      else
	{
	  Nums.push_back(temp);
	}
    }
  return Nums;
}

void sort(std::vector<double>& Nums)
{
  double min{};
  double temp{};
  size_t k{};
  bool flag{false};
  for (size_t i{}; i < Nums.size(); i++)
    {
      min = Nums[i];
      for (size_t j{ i + 1 }; j < Nums.size(); j++)
	{
	  if (min > Nums[j])
	    {
	      min = Nums[j];
	      k = j;
	      flag = true;
	    }
	}
      if (flag)
	{
	  temp = Nums[i];
	  Nums[i] = min;
	  Nums[k] = temp;
	  flag = false;
	}
    }
	
}
