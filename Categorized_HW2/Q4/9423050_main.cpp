// Mohammad Rahmdel 9423050
// *** Selection Sort ***

#include <iostream>
#include <vector>

int main(){
  std::vector <int> arr ; // all inputs
  int inp{1};//input
  std::cout<<"Please Enter ur *integer* numbers (enter 0 to end): "<<std::endl;
  while( inp != 0 ) // cin till the input is zero
    {
      std::cin>>inp;
      arr.push_back(inp); // adding new number to vector
    }
  arr.erase(arr.begin() +(arr.size()-1)); // removing  zero from vector 

  std::cout<<"Unsorted inputs : "; // showing inputs 
  for( size_t i{0}; i < arr.size(); i++)
    std::cout<<arr[i]<<" - ";

  int h{};// helps for sorting - it stores the minimum
  size_t x{};// for sorting - index of minimum element
  std::vector <int> sorted_arr(arr.size());//new vector for saving sorted numbers
  size_t n{}; 
  
  while ( arr.size() > 1 ){
    h = arr[ ( arr.size() - 1 ) ]; // assumes first element as minimum
    x = ( arr.size() - 1 );
    for(size_t i{ (arr.size() - 1) } ; i > 0 ; i--)
      {
	if( h > arr[i-1] ) // finding minimum
	  {
	    h = arr[i-1]; // changing the min
	    x = i-1 ; // changing min index
	  }
      }
    arr.erase(arr.begin() + x); // removing the last min
    sorted_arr[n] = h ; // adding min to new vector
    n++; // next number
  }
  
  sorted_arr[n] = arr[0]; // last number
  
  std::cout<<'\b'<<'\b'<<" "<<std::endl<<"Sorted inputs : ";
  for( size_t i{0} ; i < sorted_arr.size() ; i++) // showing the output :)
    std::cout<<sorted_arr[i]<< "  " ;
  std::cout<<std::endl;
  
  return 0;
}
