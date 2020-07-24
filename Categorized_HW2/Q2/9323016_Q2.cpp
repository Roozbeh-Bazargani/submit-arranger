#include<iostream>
#include<fstream>


int main()
{
  int k{};
  std:: string line{};
  std::ifstream ifile{"Error_find.txt"}; 
  while (!ifile.eof()) //checking the end of the file.
     {
       getline(ifile , line);   //getting the file as  line-by-line.  
       for(unsigned int i{} ; i<line.length() ; i++) //the loop for check the chracters in the line.
         {
	   if(!isupper(line[i])) //the command is to check for characters aren't big. 
	    {
	      switch(line[i])  // the switch case for check vowels & other things.
	        {
		   case 'a':
		     k=0;
		   break;
		   case 'e':
		     k=0;
		   break;
		   case 'i':
		     k=0;
		   break;
		   case 'u':
		     k=0;  
		   break;
		   case 'o':
		     k=0;
		   break;
		   case ')':
		     k=0;
		   break;
		   case '(':
		     k=0;
		   break;
		   case '.':
		     k=0;
		   case ' ':
		     k=0;
		   break;
		   case '-':
		     k=0;
		   default :
		     k++;   
		   break;
	         }
	    }
	   



	   if(k>=5 && (line[i+1]==' '||line[i+1]=='.'))//the condition for existance of a false word
	       {
	         while(k>0)
		  {
	            std::cout<<line[i-k+1]; //show the wrong words.
	            k--;
	          }
	         std::cout<<std::endl; 
                 k=0;
	       }
	    
	 }
        
     }
  
  ifile.close();
  return 0;
}

