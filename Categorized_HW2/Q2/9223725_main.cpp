#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<iomanip>

bool is_lowercase(std::string,size_t, size_t);//for checking all letter of a word

int main()
{
  std::string text; 
  std::string temp; //temporary variable for reading words
  std::ifstream in_file; //input file
  std::vector<std::string> words; //vector of words
  const std::string separators{"-./(){}[]"};
  const std::string consonants{"QqWwRrTtYyPpSsDdFfGgHhJjKkLlZzXxCcVvBbNnMm"};
  in_file.open("Error_find.txt");
    if(in_file.is_open())
    {
      
      while(in_file>>temp)
	{
	  size_t first{};
	  while((first=temp.find_first_not_of(separators,first)) !=std::string::npos) //finding the begging of a word
	    {
	      size_t last{temp.find_first_of(separators,first)}; //findig the end of a word
	      if(last==std::string::npos)
		last=temp.length();
	      words.push_back(temp.substr(first,last-first));
	      
	      first=++last;

	    }
	  
	}
    }
    
  in_file.close();
  size_t count{};
  std::cout<<"============Words============"<<std::endl; //printing all words
  for(auto word:words)
    {
      
      std::cout<<std::setw(15)<<word;
      if(!(++count % 5))
	std::cout<<std::endl;
    }


  std::cout<<"\n\n=========Wrong words========="<<std::endl;
  
  
  for (auto word:words)
    {
      
      if(word.length()>4)
	{
	  size_t start{};
	  while((start=word.find_first_of(consonants,start)) !=std::string::npos) //finding the start of consonant letters in a sequence 
	    {
	      size_t end{word.find_first_not_of(consonants,start)}; //finding the end of consonant letters in a sequence 
	      if(end==std::string::npos)
		end=word.length();
	      if((end-start)>4 && is_lowercase(word,start,end))
		std::cout<<word<<std::endl; 

	      start=++end;

	      
	    }
	}
    }
}

bool is_lowercase(std::string str,size_t s, size_t e)
{
for(size_t i{s};i<e;i++)
  if(str[i]==std::tolower(str[i]))
    return true;
 return false;
};
