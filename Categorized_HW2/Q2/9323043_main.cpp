#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

int main(){


  std::string text;
  std::string arr;         //for cout error world
  int counter{};           //for counting alphabets
  int k{};                  //for array index to display wrong word
  char space =' ';;
  
  std::ifstream ifile{"Error_find.txt",std::ios::app};
  
  
  while( !ifile.eof())      //until the file is not ended
  text +=ifile.get();
  
   
     std::cout<<text;
    
      
  
  ifile.close();
  
   
  
  for( size_t i{} ; i<text.length() ; i++)
    {
      if (text[i] == space ){
        
	k=0;    //index for array to save wrong word
	counter=0;
      }
      if (static_cast<int>(text[i])>90 )    //lower alphabet(a-b-..)

	{
	  switch (text[i]){
	  case 'a' :case 'e' : case 'i' :case 'o' :case 'u' :
	    counter=0;
	    break;
	  default :
	    ++counter;
	    
	    arr[k]=text[i];  //for saving wrong word to Display
	    k++;
	    
	    
        	    
	    
	    
	      
	      if (counter == 5){
	      std::cout<<"the wrong  word is : "<<std::endl;
	     
	      for (int j{} ; j<k ; j++)
		std::cout<<arr[j];    //Displaying the wrong word
	      std::cout<<std::endl;
	      std::cout<<std::endl;
		k=0;                  //array index
		counter=0;  
	    
	      }
	     
		
	      
	      
	      break;
	}
    }
    }

  

  return 0;
}
