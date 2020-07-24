#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector> 
using std::string;
using std::copy;

std::ifstream ifile{"Error_find.txt"};

int main()
{
  size_t k{};
  std::string text;
  std::ifstream ifile{"Error_find.txt"};    // Input File
  if(!ifile)         // Check if the file is open or not
    {
      std::cout <<"File can not open!"<< std::endl;
      return 1;
    }
  std::vector<string> words;
  while ( ifile >> text )
    {
      const string separators { " ,;:.\"!?()0123456789'\n" }; 
      std::vector<string> words;
      size_t start { text.find_first_not_of(separators) };   // First word start index
      size_t end {};   // Index for end of a word
      while (start != string::npos)   // Find the words
	{
	  end = text.find_first_of(separators, start + 1);   // Find end of word
	  if (end == string::npos)   // Found a separator?
	    end = text.length();   // No, so set to last + 1
	  words.push_back( text.substr(start, end - start) );    // Store the word
	  start = text.find_first_not_of(separators, end + 1);   // Find 1st character of next word
	}
      string s="";
      char s1{};
      for ( const auto& word : words )    // Separation of letters in a word
	{
	  for ( size_t j{}; j<= word.size();)
	    {
	      s += word[j];
	      s1 = word[j];
	      if (s1=='a' ||  s1=='e' ||  s1=='i' ||  s1=='o' ||  s1=='u' || (s1>='A'&& s1<='Z'))   // Checking for vowel letters and A to D
		j++ ;
	      else
		{
		  j++ ;
		  k++ ;
		}
	    }
	  if ( k >= s.length()  )   // Find wrong words in text and print them 
	    if ( k>=5 )
	      std::cout << std::setw(10) << s ;
	  k=0 ;
	  s="";
	  s1=0;
       }
    }
  std::cout << std::endl;
  return 0;
}



