#include<iostream>
#include<fstream>


bool error_check(const std::string& ); // functions that checks the

std::string delete_delimiter(std::string); // a function that removes non-alphabetic characters



int main()
{
  
  std::ifstream text_obj{"Error_find.txt"}; // importing the txt file to an object
  
  std::string word{}; // the letter that we check its correctness
  std::string errors{}; // all detected errors in a string


  // a loop for check each letter of text :
  
  while( text_obj >> word ){

    if( error_check ( delete_delimiter ( word )))
      
      errors = errors + word + "\n" ; // making the list of errors
  }

  std::cout << "the errors are :\n \n" << errors << std::endl; // showing the error list
  
  text_obj.close();
  
 }



// functions that checks the existence of error -------------------------------

bool error_check(const std::string& word){

  size_t no_vowel{}; // number of no_vowel letters
  size_t capital{}; // number of capital letters
  

  // a loop for checking each letter
  
  for(size_t i{}; i < word.size() ; i++ ){
    
    switch ( word[i])

      {
      
      case 'a': case'e':case 'i': case'o':case 'u':
      case 'A': case'E':case 'I': case'O':case 'U':

	{
	  no_vowel=0; // reseting no_vowel counter when we have vowels 
	  break; // break the switch  when we have vowels
	}

	
      default :

	no_vowel++; // counting no-vowels
	
      }

    if ( word[i] >= 'A' && word[i] <= 'Z' ) capital++; 

    if ( capital == word.size() ) return false; // check that is the word an abbreviation or not
    if ( no_vowel >= 5 ) return true; // if we have 5 no-vowels (or more) it returns true that means it is error ! 
  }

  return false; 
}


// a function that removes non-alphabetic characters ---------------------------

std::string delete_delimiter(std::string word){
  
  for(size_t i{} ; i < word.size() ; i++)
    
    if( !( ( word[i] >= 'a' && word[i] <= 'z') || ( word[i] >= 'A' && word[i] <= 'Z')))
      {
	word.erase(i,1);
      }
  
  return word;
}
