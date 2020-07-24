/*
AP-HW2-Q4
9423054
*/

#include <iostream>
#include <vector>
#include<iomanip>

void sort (std::vector<double>&); //declaration of function 
  

int main ()
{

  std::vector<double> arr; //vector to store all input values
  double value{}; //stores input 
  
 
  
  std::cout << "\n Please Enter Your Non-zero Array of Numbers "
            <<" (Enter 0 to Start Sorting!)\n" << std::endl; 
  
  
  while (1) //loop for getting input values
  {
    std::cout << "Enter Number:" << std::endl;

    std::cin >> value;

    if (value == 0) //if user enters 0, goes out of loop
      break;
    
    arr.push_back(value); //passing input values to vector
    
  }

 
  
  sort( arr ); //sort function runs with input vector
  

  //Printing Output -----
  
  std::cout << "\n -------- \n" 
             << "Your Array in Ascending Order:\n" << std::endl;

   size_t n{}; //counts output numbers
  
   for (size_t k{}; k < arr.size() ; k++) //loop for printing output
     {
       std::cout<< std::setw(8) << arr.at(k);
       
       if (++n == 10) //prints only 10 numbers in a line
       {
	 std::cout << std::endl;
	 n = 0;
       }
     }
          std::cout << "\n" << std::endl;

     //---
	  
	  
  arr.clear(); //clears all vector elements to free up memory
   
  return 0;

}

/* sort function:

 * @breif: This function sorts all input vector elements in ascending order 
           using "selection sort"
 *
 * @params  this function takes one input arguments, a is a vector of type double
            passed by refrence
 * 
 
 * @retval  this function has no output

 */

void sort (std::vector<double>& a)
{

  double min {}; //stores minimum
       size_t j{}; //stores number of first unsorted element
          size_t swap{}; //stores number of element needs to be swapped
	  size_t size = a.size(); //size of vector
	  bool flag{false}; //a flag determines when to swap elements

  while ( j < size )
    {

    min = a[j]; //setting the first unsorted element as minimum
    
    for (size_t i{j+1} ; i < size  ; i++)
          //loop runs for unsorted elements

      {
          if ( a.at(i) < min ) //finds minimum among unsorted elements
	    {
	      min = a.at(i);
	      swap = i;        //stores the number of minimum elements to swap
	      flag = true;     //determines when to swap
	    }
       }
  
         if (flag) //swapping
	   {
	     a.at(swap) = a.at(j);
	     a.at(j) = min; 
	   }

	 j++; //next unsorted element

	 flag = false; //resets

	}
}
