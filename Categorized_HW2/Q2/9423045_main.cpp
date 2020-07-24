#include <iostream>
#include <fstream>
#include <string>

bool isDontCare(char); //determines whether the char is number or sign 
bool isVowel(char); //determines whether the char is vowel
bool isUpper(std::string); //determines if the string is an abbreviation

int main()
{
  std::ifstream output{ "Error_find.txt" }; //input file stream for text file
  std::string str{ "" }; //for keeping the word
  int ctr{}; //counts the consonants

  output >> str; 

  while (!output.eof()) //until the file ends
    {
      if (str.length() > 4 && !isUpper(str)) //skip if the word is too short or abbreviation
	{
	  if (isDontCare(str[str.length() - 1])) //erasing unwanted chars from beginning and end of word
	    {
	      str.erase((str.length() - 1), 1);
	    }
	  if (isDontCare(str[0]))
	    {
	      str.erase(0, 1);
	    }
	  ctr = 0; //counter
	  for (size_t i = 0; i < str.length() && ctr != 5; i++)
	    {
	      if (isVowel(str[i])) //vowels change the rule
		{
		  ctr = 0;
		}
	      else if (!isDontCare(str[i]))
		{
		  ctr++;
		}
	    }
	  if (ctr > 4)// it's a mistake and should be printed
	    {
	      std::cout << str << '\t';
	    }
	}
      output >> str;
    }
  std::getchar();

	return 0;
}

bool isDontCare(char input)
{
  char set[]{ '(',')',' ','.','-',',','1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'0' };

  for (char c : set)
    {
      if (input == c)
	{
	  return true;
	}
    }
  return false;
}

bool isVowel(char input)
{
	char set[]{ 'a','e','i','o','u' };
	for (char c : set)
	{
		if (tolower(input) == c)
		{
			return true;
		}
	}
	return false;
}

bool isUpper(std::string s)
{
  for (char c : s)
    {
      if (c != toupper(c))
	{
	  return false;
	}
    }
  return true;
}
