#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

int main()
{
  std::string text;
  std::ifstream my_text;
  std::vector<std::string> words;
  
  my_text.open("Error_find.txt");
  
  if(my_text.is_open())
    {
      while(getline(my_text,text))   //countinue to the end of file
	{
	   const std::string separators{" ,;:.\"!?'\n()"};
	   size_t start { text.find_first_not_of(separators) };
	   size_t end{};
 
	   while (start !=std::string::npos)     // Find the words
	    {
	      end = text.find_first_of(separators, start + 1); 
	      if (end == std::string::npos)// Found a separator?
		{
		  end = text.length();// No, so set to last + 1
		}
	      
	      words.push_back(text.substr(start, end - start));

	       // Find 1st character of next word

	      start = text.find_first_not_of(separators, end + 1);	      }
 
	}
    
  my_text.close();
}

  
 for(size_t i{}; i < words.size() ;i++)
   {
     size_t count{};
     size_t count_upper{};        //to count number of big letter
    
     if(words[i].size() >= 5)    //size of each word
       {
	 for(size_t j{}; j < words[i].size() ; j++)
	   {
	     if(std::isalpha(words[i][j]))  
	       {
		 if(std::isupper(words[i][j]))
		   {
		     count_upper+=1;   
		      switch(words[i][j])
		       {
		         case'A': case'E': case'I': case'U': case'O':
			 count = 0;
			 break;

   		         default:
			   count ++;  //to count number of consonants
			 break;
		       }
		   }
		 else if(std::islower(words[i][j]))
		   {
		     switch(words[i][j])
		       {
		       case'a': case'e': case'i': case'u': case'o':
			 count = 0;
			 break;

		       default:
			 count ++;
			 break;
		       }
		 
		   }
	       }
	   }
        }
     if(count >= 5 && count_upper !=words[i].size())
       {
	  std::cout << words[i]<<std::endl;
       }
     count = 0;
   }


  return 0;
}
