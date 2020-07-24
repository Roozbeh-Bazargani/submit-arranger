#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>


int main()
{ 
  size_t consonant{};
  std:: string text{};
  
  std:: ifstream myReadFile;
  myReadFile.open("Error_find.txt");     // open the textfile

 
  while(myReadFile >> text)    //the whileloop runs until the text completed
   {
     std:: string word = "";  
 consonant = 0;
 for ( size_t i{} ; i<text.length() ; ++i )  //for loop does for every word
    {
     
      if(isalpha(text[i]) && islower( text[i]))  //run the next command if it's letter and small
	{

	  switch(text[i])
	    {
	    case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
	      consonant = 0;   //if it's vowel start counting from 0
	      break;
	    default:
	      consonant++;  
	      word+= text[i];  // adding new letter of string 
	      break  ; 
	    }
	}
    }
 if (consonant >= 5)
   std::cout << word<< std::endl;
   }

  myReadFile.close();  //close the textfile

  return 0 ;
}
