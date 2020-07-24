#include<iostream>
#include<vector>

void sort(std::vector<double> &); //Selection sort
void show(const std::vector<double> &); // display numbers
void swap(std::vector<double> &, size_t, size_t); // swap 2 numbers

int main()
{
  double x{ 1 };
  std::vector<double> v{}; // For storing inputs
  std::cout << "Enter numbers for sorting (Stop with 0): ";
  while (1)
    {
      std::cin >> x;
      if (x == 0) //checking for stop getting inputs
	break;
      v.push_back(x); //Storing inputs
    }

  sort(v); //sort vector
  show(v); //display vector
  return 0;
}

void sort(std::vector<double> &v)
{
  size_t min{};
  for (size_t i{}; i < v.size(); i++)
    {
      min = i;
      for (size_t j{ i + 1 }; j < v.size(); j++) // Searching through all numbers
	{
	  if (v[j] < v[min]) // Searching for minimum
	    min = j;
	}
      swap(v, i, min); // swap minimum with first number of the remaining one
    }
}

void show(const std::vector<double> &v)
{
  for (double x : v)
    std::cout << x << " ";
  std::cout << "\n";
}

void swap(std::vector<double> &v, size_t a, size_t b)
{
  double c{ v[a] };
  v[a] = v[b];
  v[b] = c;
}
