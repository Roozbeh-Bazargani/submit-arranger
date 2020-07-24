#include<iostream>
#include<fstream>
#include<string>

void check(std::string);  //  To check if the word is wrong!
bool is_consonant(char);  //  To check if the character is consonant and lower-case

int main()
{
  std::ifstream ifile{"Error_find.txt"};
  std::string s{};
  //  Importing words from txt file and checking them!
  while (1)
    {
      ifile>>s;
      if (ifile.eof()) break;
      check(s);
    }
}

void check(std::string s)
{
  size_t counter{};  //  Number of successive consonant characters in a word
  std::string temp{};
  if (s.length()>4)
    {
      for (size_t i{};i<s.length();i++)
	if(is_consonant(s[i]))
	  {
	  if (++counter>=5)
	    {
	      temp=s;
	      if(temp[temp.length()-1]=='.')temp[temp.length()-1]=' ';
	      std::cout<<temp<<std::endl;
	      break;
	    }
	  }
	else
	  {
	    counter=0;  //  when a character is not consonant and lower-case
	  }
    }
}

bool is_consonant (char x)
{
  bool flag=true;
  char vowels[]{'a','e','i','o','u'};
  if (x>='a' && x<='z')
    {
      for (auto i:vowels)
      if (x==i) flag=false;
    }
  else
    {
      flag=false;
    }
  return flag;
}
