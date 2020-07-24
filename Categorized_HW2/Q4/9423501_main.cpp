#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
  size_t N{}, i{};
  int num[1000];
  int item{};
  std::cout << "Please Enter Numbers: " << std::endl;
  while ( num[i]==0 )  // User must enter numbers by This loop 
    {
      std::cin >> num[i] ;
      if ( num[i]!=0 )
	i++ ;
      else
	break;
    }
  N = i;

  //  Selection Sort Algorithm
  
  for ( size_t i{}; i < N-1; i++ )  
    for ( size_t j=i+1; j < N; j++ )
      if ( num[i] > num[j] )
	{
	  item = num[i] ;
	  num[i] = num[j] ;
	  num[j] = item ;
	}
  std::cout << "Numbers were sorted by Selection Sort Algorithm: " << std::endl;

  // Sorted Numbers are printed by this loop  
  
  for ( size_t i{}; i < N; i++ )
    std::cout << num[i] << std::setw(10) ;
  
  std::cout << std::endl;
  
  return 0;
}
