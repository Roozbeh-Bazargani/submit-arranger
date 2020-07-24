#include<iostream>
#include<fstream>
#include<string>

void find_error(std::string);

int main()
{
  std::ifstream ifile{"Error_find.txt"};//opening the file in the program;
  
  if( !ifile ) //if file can't be found
    {
      std::cout<<"file not found"<<std::endl;
    }
 
  std::string content{};//an array for saving the alphabets
  while(!ifile.eof())//untli the end of the file
    {
      getline(ifile,content);//placing each sentence of file in content
      std::cout<<content<<std::endl;//showing the sentence
      find_error(content);
    }
      
  ifile.close();//closing .txt file
  return 0;
}



void find_error(std::string content)
  {
     int k{};//for counting the number of consonants 
      for(unsigned int  i{};i<content.length();i++)
      {
	if( ! isupper(content[i]))//consider just the lower cases
	  	  {
	    switch(content[i]){
	    case 'a'://checking the cases
	      k=0;
	      break;
	    case 'o':
	      k=0;
	      break;
	    case 'i':
	      k=0;
	      break;
	    case 'u':
	      k=0;
	      break;
	    case 'e':
	      k=0;
	      break;
	    case '(':
	      k=0;
	      break;
	    case ')':
	      k=0;
	      break;
	    case '.':
	      k=0;
	      break;
	    case '-': 
	      k=0;
	      break;
	    case ' ':
	      k=0;
	      break;
	      	    default:
	      k++;}
	 }
	
	//checking if k is 5 or less
	if(k>=5 && (content[i+1] == ' ' || content[i+1] =='.'))
	{
	  while(k>0)
	    {
	      std::cout<<content[i-k+1];
	      k-=1;
	    }
	  std::cout<<std::endl;
	  k=0;
	}
             
      }

  }

