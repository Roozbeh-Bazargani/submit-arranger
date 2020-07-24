#include<iostream>

int main()
{
  double arr[30];
  int count{};
  std::cout << "Please enter numbers: " << std::endl;
  std::cin >> arr[count];
  // take number from user while entered 0.
  while(arr[count] != 0)
    {
      count++;
      std::cin >> arr[count];
    }
  // comparing member of array
  for(int i{}; i < (count-1); i++)
    {
      for(int j = i+1; j < count; j++)
	{
	  if(arr[j] < arr[i])
	    {
	      double temp = arr[i];
	      arr[i] = arr[j];
	      arr[j] = temp;
	    }
	}
    }
  // display sorted array
  std::cout << "sorted numbers is: " << std::endl;
  for(int i{}; i < count; i++)
    {
      std::cout << arr[i] << "  ";
    }
  std::cout << std::endl;
  return 0; 
}
