/*
AP-HW2-Q2
9423054
*/

#include<iostream>
#include<fstream>
#include<string>
#include<locale>
#include<vector>


//declaration of functions

  void towords (const std::string, std::vector<std::string>&);
  void finderrors (const std::vector<std::string>);
  

int main()
{

  std::string txt;  //stores input file's text
 
  std::vector<std::string> words; //stores each word of input text

  
  std::ifstream ifile{"Error_find.txt"};  //opening text file

  if (!ifile)
    {
      std::cout << "File not found!" << std::endl;

      return 1;
    }

  //stores all contents of text file in string txt
  txt.assign( (std::istreambuf_iterator<char>(ifile) ),
	    (std::istreambuf_iterator<char> ()));
  

  ifile.close(); //closing file


  towords (txt, words);  //stores all words in string in a vector

  std::cout<< "Errors found in this text are:" << std::endl;
  
   finderrors(words);      //finding errors in text
     

  

  return 0;
}


/* towords function:

 * @breif: This function reads the input string and stores all words in it 
           in a vector of type string
 *
 * @param  this function takes two input argument, txt as a string
           and words as a reference to a vector of type string
 *
 
 * @retval  this function has no return value, it just changes the given vector

 */

void towords (const std::string txt, std::vector<std::string>& words)

{

   const std::string separators { "()- ,;:.\"!?'\n" };
  //all charactors in text that sepaerate words

  size_t start { txt.find_first_not_of(separators) };
  //start of first word

  size_t end {};
  //end of word

     while ( start != std::string::npos ) 
        { //this loops works until it reaches end of file
     
	  end = txt.find_first_of(separators, start+1);
          //finds end of word, by searching for first separatore after start
     
	  if (end == std::string::npos)
	   //if it reaches end of file, end is number of last character
	    end = txt.length();

	  words.push_back (txt.substr (start, end - start));
          //passes a substring (word) to output vector
       
	  start = txt.find_first_not_of(separators, end+1);
	   //finding start of next word
	}

     }



/* finderrors function:

 * @breif: this function finds all defined errors in each word of
           input string 
 *
 * @param: this function takes one input argument, words as a vector of
            type string 
 *
 
 * @retval: this function returns no value, it just prints the mistaken words

 */

  void finderrors (const std::vector<std::string> words)

  {


    size_t up_const{}; //counts number of upper constants in a row
    size_t low_const{}; //counts number of lower constants in a row 

      for (auto& word : words)
        {  //this loop runs for each word of text

	  up_const = 0; //reseting for each word
	  low_const = 0;
	  
            for (size_t i{}; i < word.length(); i++)
	      {  //runs for every character in a word
		
		switch ( word[i] )
		  {
		  case 'a'  : case 'i' : case 'e' : case 'o' : case 'u' :
		    case 'A'  : case 'I' : case 'E' : case 'O' : case 'U' :
		    
	

		    if  (low_const >= 5 || up_const >= 5 || up_const + low_const >= 5)
                      //if error is found stop 
		     break;
		    
		    up_const = 0; //vowel is found
		    low_const = 0;
	  
		    break;

	          default : 
	  
		   if(std::isupper(word[i])) 
		     up_const++;
	       
		   else
		     low_const++;

	  	  break;

	           }
	
                }
   
      
     	    if  ( !( up_const == word.length() && low_const == 0 ) &&
		  (low_const + up_const)  >= 5)
	      //error found 
	      std :: cout << "\t"  << word << std::endl ;
	   	 
	 }

       }
