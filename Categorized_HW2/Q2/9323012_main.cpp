#include<iostream>
#include<fstream>


int main(){
  int flag{}; size_t flags{};
  std::ifstream file;
  file.open("Error_find.txt");
  std::string word;
  while(file >> word)
    {
     
      if ( word[4] != 0 )
	{
	  flag =0;
	  for(size_t i{}; i < word.length() ; i++)
	    { flags=0;
	      for(size_t j{}; j < word.length() ; j++)
	      if (word[j]<97)
		flags++;
	      if (flags > 4)
		break;
	     if (word[i] != 'a' && word[i] != 'i' && word[i] != 'o'
		 && word[i] != 'e' && word[i] != 'u' )
	      { flag++;
		if(flag == 5)
		  std::cout << word <<std::endl;
	      }
	      else
		flag = 0;
	    }
	}
       
          }  
    return 0;
}
