#include <iostream>
#include <iomanip>
#include <vector>

 
int main()
{
std::vector<double> x; // Stores data to be sorted
double temp {};   // Temporary store for a value
 
while (true)
{
  std::cout << "Enter a non-zero value, or 0 to end: ";
  std::cin >> temp;
    if (!temp)
    break;
 
    x.push_back(temp);
 }
 
bool swapped {false};  // true when values are not in order
while (true)
{
  for (std::vector<double>::size_type i {} ; i < x.size() - 1 ; ++i)
   {
     if (x.at(i) > x.at(i + 1))
      { // Out of order so swap them
       temp = x.at(i);
       x.at(i) = x.at(i + 1);
       x.at(i + 1) = temp;
       swapped = true;
       }
   }
   if (!swapped)   // If there were no swaps
   break;   // ...they are in order...
   swapped = false;  // ...otherwise, go round again.
}
 
 std::cout << "your data in ascending sequence:"<<std::endl;
 
 for (std::vector<double>::size_type i {} ; i < x.size() ; ++i)
{
  std::cout <<x[i]<<"\t";  
}
 std::cout<<std::endl;
 return 0;}
