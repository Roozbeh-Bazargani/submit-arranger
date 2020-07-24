// Mohammad Rahmde 9423050
// Simple Error finder

#include <iostream>
#include <fstream>
#include <string>

bool check(std::string , size_t);
bool last_check(std::string , size_t , size_t );

int main(){

  std::string inh,inp{""}; // input
  std::ifstream in;
  in.open("Error_find.txt"); // reading input (text name must be Error_find)
  getline( in , inh );
  while( in ){ // text to string
    inp += inh;
    getline( in , inh );
  }

  std::string res;//result = output
  size_t i{}; // end character of each word
  size_t j{}; // first ....................
  std::string test; // test for checking each word 

  while(i < inp.length()-1 ){ 
    j = i;
    while(inp[i] != ' ') // seperating each word
      i++;

    if(i>inp.length()) // prevents from out of range error
      i = inp.length()-1;
       
    test.append(inp,j,(i-j)); // each word puts in test
    test.append(" ");
      
    if(check( test,(i-j) ) ) // checking if it is correct or not 
      res.append(test); // if it's wrong it test appends to result
    
    test.clear();
    i++; // next character
 }
  
  i = 0;
  while( i < res.length()-1 ){
    i++;
    if( (isalpha(res[i-1]) == 0 ) && (res[i-1] != ' ') ) //removing non alphabet characters (space is exception)
      {
	res.erase(i-1,1); // removing syntax
	i--; 
      }
  }
  
  i = 0;
  while( i < res.length()-1 ){
    j = i;
    while(res[i] != ' ')
      i++;

    if( i > res.length() ){
      i = res.length()-1;
    }
    
    if( last_check(res,j,i) ) // checking for abbreviations
      {
	res.erase(j,(i-j+1)); // removing abbreviations from output
      }
    i++;
  }
  std::cout<<"Output :"<<res<<std::endl;     
  return 0;
}

bool check(std::string s, size_t N) //dictation checker
{
  size_t cnt{};
  size_t i{};
  bool quit{};
  while( (i < N) && ( quit == 0 )) {
    if //*** "y" is not considered as a vowel letter ***
      ( s[i] == 'e' || s[i] == 'a'||  s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
	  cnt = 0;
    else if
      ( s[i] == 'E' || s[i] == 'A'||  s[i] == 'I' || s[i] == 'O' || s[i] == 'U' )
	  cnt = 0;
    else 
	  cnt ++;

    if(cnt>4) // check for exceptions
      {
	if( ((isupper(s[i]))&&(isupper(s[i-1]))&&(isupper(s[i-2]))&&
	     (isupper(s[i-3]))&&(isupper(s[i-4]))) == 0)
	  quit = 1 ;
	else {
	  cnt = 0;
	}
      }
    i++;
  }

  if( cnt > 4 )// if it has more than 4 non vowels
    return 1;
  else
    return 0;
}


bool last_check(std::string str, size_t a, size_t b){
  std::string temp {str};
  size_t cnt{};
  str.clear();
  str.append(temp,a,(b-a));
  size_t i{};
  while( i < str.length() )
    {
      if ( isupper(str[i]) ) // check if it's uppercase or not
	cnt++;
      i++;
    }
  if( cnt == str.length() ) //if all letters are Uppercase
    return 1;
  else
    return 0;
}
