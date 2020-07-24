#include<iostream>
#include<fstream>


int main(){
  std::string f{};
  bool flag{false};
  bool flag2{false};
  unsigned j{};
  int counter{};
  //accessing to the file 
  std::ifstream file{"Error_find.txt"};
  //entering the word of file into f string
  while(file >> f){
    //check the length of the word
    if(f.length() > 4){
      //make the circle to that qoes 5 by 5  and check the word
       for(unsigned k{}; k < (f.length() % 5) + 1; k++){
	 j = k;
	 counter = 0;
	 // check if each 5 alphabets of word contain any vowel alphabet  
	 for(; j < 5 + k; j++){
                 if(f[j] == 'a' || f[j] == 'e' || f[j] == 'i' || f[j] == 'o' ||
		    f[j] == 'u'){
		   // if there is any make the flag true
	            flag = true;
		    break;
		 }
		 
	         else
		   counter++;
	           
         	}
	 // if check all the 5 alphabet 
	 if ( counter == 5){
	     flag = false;
	     break;}
	 
               
       }
      int stringint{};
      //if there is no vowel alphabet check if they are uper case or not 
      if(flag == false){
	for(unsigned p{}; p  < f.length(); p++){
	  stringint = (int)f[p];
	  if(stringint >= 97 && stringint <= 122){
	    flag2 = true;
	    break;
	  }
	}
	//print the wrong words
	if( flag2 == true)
        	std::cout << f <<std::endl;
      }
      flag = false;
      flag2 = false;
     
       
      


       } 
  
 }

  

  return 0;
}
