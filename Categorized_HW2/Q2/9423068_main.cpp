#include<iostream>
#include<fstream>
#include<string>

void Error_find_func(std::string);

int main()
{
  std::string word;
  // opening file for reading word by word
  std::ifstream myfile{"Error_find.txt"};
  // reading word while reaching end of file
  while(myfile >> word)
    {
      // calling function for find false word
      Error_find_func (word);
    }
  
  return 0;
}

void Error_find_func(std::string word)
{
  std::string vowel{"aeiouy"}, VOWEL{"AEIOUY"};
  int length = word.length();
  // finding number of capital letter & all letter of word
  int count{}, count_cap{},letter{};
  // study words that have higher than 5 letter
  if(length >= 5)
    {
      for(int i{}; i < length; i++)
	{
	  if('A'<= word[i] && word[i]<='Z')
	    {
	      letter++;
	      count_cap++;
	      count++;
	      for(int j{}; j < 6; j++)
		{
		  if(word[i] == VOWEL[j])
		    count = 0;
		}
	    }
	  else if('a'<= word[i] && word[i]<='z')
	    {
	      letter++;
	      count++;
	      for(int j{}; j < 6; j++)
		{
		  if(word[i] == vowel[j])
		    count=0;
		}
	    }
	  else
	    {
	      count = 0;
	    }
	  if(count == 5)
	    break;
	 
	}
      // if all letter of word is capital don't cout it
      if(count==5 && count_cap != letter)
	{
	  for(int k{}; k<=length; k++)
	    {
	      if((word[k]>='a'&&word[k]<='z')||(word[k]>='A'&&word[k]<='Z'))
		std::cout << word[k];
	    }
	  std::cout << std::endl;
	}
    }
}
