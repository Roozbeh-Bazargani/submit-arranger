#include<iostream>
#include<fstream>

size_t get_numbers (); //function that gets numbers from user and save them into a textfile.

void save_numbers(int*); // function that reads saves numbers in text file anf save them into a dynamic variable

void sort_numbers(int*, size_t); // functions that sorts numbers in ascending order.


int main()
{
  
  size_t counter{}; // number of numbers.
  
  int* numbers{new int[counter]}; // the array of input  numbers
  
  counter = get_numbers(); // (explained)
  
  save_numbers(numbers); // (explained)
  
  sort_numbers(numbers,counter); // (explained) 


  // showing the result :

  std:: cout << "\nsorted numbers : \n" ;
  
  for ( size_t i{} ; i < counter ; i++ )
    
    std::cout << numbers[i] << std::endl;
  
 }


// function that gets numbers from user and save them into a textfile. -----------

size_t get_numbers (){
  
  size_t counter{}; // counter of input numbers
  int input_num{}; // input number variable
  
  std::cin >> input_num ; // here, we get first number from user
  
  std::ofstream of{"numbers.txt"}; // create an text file to save input numbers in it

  // this loop gets numbers from user and saves them in the text file until the user sends zero ( 0 ) ::
  
  while ( input_num != 0 ){
    
    of << input_num << "\t";
   
    counter++;
    
    std::cin >> input_num;
  }
  
  of.close(); // closing object
  
  return counter; // return number of inputs
}



// function that reads saves numbers in text file anf save them into a dynamic variable -------------------

void save_numbers( int* numbers)
{
  
  std::ifstream num_ifile{"numbers.txt"}; // creates an object from the text file containing the input numbers
  
  size_t index_num{};

  // transfering numbers from text file to array :
  
  while ( num_ifile >> numbers[index_num] )
    
    index_num++;
  
  num_ifile.close();
  
}



// functions that Sorts numbers in ascending order. -----------------------------
// The Selection Sort Algorithm :

void sort_numbers(int* numbers, size_t counter)
{
  int temp{}; // a temp variable


  // this loops compare each number with others and change the place of them (in array ) if its needed :
  
    for ( size_t i{} ; i < (counter-1) ; i++ )
      
      for ( size_t j{i+1} ; j < counter ; j++ )
	
	  if ( numbers[i] > numbers[j] )
	    {
	      temp = numbers[i];
	      
	      numbers[i] = numbers[j];
	      
	      numbers[j] = temp;
	    }	     
}
