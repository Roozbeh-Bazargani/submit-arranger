#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

void selection_sort ( std::vector<int>& , int); // declaration of void function


int main()
{ 
  std::vector<int>p ;   
  int temp {};

  while (true)
    {
      std::cout << "enter a non_zero value, or 0 to end" << std::endl;
      std::cin >>temp ; //get number from user
      if (!temp)
	break;
      p.push_back(temp); //insert number at the end of the vector
    }

  selection_sort ( p , p.size()) ;  //sort the numbers from small to large

  std::cout << "the sorted numbers are:" <<std::endl;
 for ( size_t i{} ; i< p.size() ; i++)
     {
       std::cout << p.at(i) << std::endl;  
       
     }
 return 0;
}




void selection_sort ( std::vector<int>& p , int n)  //function definition
{                                                  //the function swap two numbers
  int  max{} ;
int  vaset{} ;
  
  for (int i{n -1} ; i> 0 ; i--)
  {
    max = 0;
    for (int j {1} ; j <= i ; j++)
      {    
  if ( p.at(max) <p.at(j))
        max = j;
    vaset = p.at(i);
    p.at(i) = p.at(max);
    p.at(max) = vaset;
  }
}
}
