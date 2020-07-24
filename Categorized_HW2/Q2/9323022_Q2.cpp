#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;

int main()
{
  std::ifstream input_file{"Error_find.txt"}; //input txt file
  while(!input_file.eof()) //do until end of file
    {
      std::string s;
      input_file >> s; //get a word
      if (s.length() < 5) //ignore words with less than 5 letters
	continue;

      unsigned int plate{0};
      
      for (unsigned int i{0}; i < s.length(); i++) //check upper case letters in s
        if ((s[i] >= 65) && (s[i] <= 90))
	  plate++;
      
      if (plate == s.length()) //ignore abbreviation words
	continue;

      unsigned int end=5;
      for (unsigned int j{0}; j < end; j++) 
	{
	  if ((s[j] == 'e') || (s[j] == 'y') || (s[j] == 'u') || (s[j] == 'i') || (s[j] == 'o') || (s[j] == 'a') || (97 > s[j]) || (s[j] > 122))
	    {
	      if((j+6) <= s.length())
		end = (j+6);// check next 5 letters
	      else
		break; //word is correct
	    }
	  if (j == (end-1)) //a wrong word found
	    {
	      for (unsigned int k{0}; k < s.length(); k++) //use this to prevent printing . - : ;
		if (((s[k] >= 65) && (s[k] <= 90)) || ((s[k] >= 97) && (s[k] <= 122)))
		  cout << s[k];
	      cout << " ";
	    }
	}
    }
  cout << endl;
  return 0;
}
