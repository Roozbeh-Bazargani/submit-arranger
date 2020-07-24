#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

int main(){
  /*flags b and b1 for checking the the text contain a,e,i,o,u 
    and also checking the lower case or upper case*/
  bool b{false};
  bool b1{true};
  std::string s{};
  unsigned i{};
  int count{};
  // read the words from file.
  std::ifstream ifile{"Error_find.txt"};
  if (ifile.is_open()){
   while(ifile >> s){
     if(s.length() >= 5){
       for(unsigned k{}; k < (s.length()%5)+1; k++){
	 i = k;
	 count=0;
	 /*checking each whether word has a,e,i,o,u or no ?*/
	 for(; i < 5+k ; i++){
	   if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
	     b = true;
	     break;
	   }
	   else
	     count++;  
	 }
	 //if the word has 5 lower case near eachother break the for
	 if(count == 5)
	 {
	   b = false;
	   break;
	 }
	 
       }
      
      
       // check whether all of the word alphabet is lower case or not?
       int toint{};
       if(b == false){
	 for(unsigned j{} ; j < s.length() ; j++){
	   toint = (int)s[j];
	   if(toint >= 97 && toint <= 122){
	     b1 = false;
	     break;
	   }

	 }
	 //print the false word
	 if( b1 == false)
	   std::cout << s << '\t';
       }
       b = false;
       b1 = true;
     }
   }
  }

  ifile.close();
  std::cout << std::endl;
  return 0;

  
}
