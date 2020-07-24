#include<iostream>
#include<string>
#include<fstream>

void check(std::string);         //this function is for finding the wrong words

int main(){
  std::string text{""};         //pass each word to this string
  std::ifstream ifile{"Error_find.txt"};     //reading the file
  std::cout << "wrong words are : " << std::endl;
  std::cout << "*******************" << std::endl;
  ifile >> text;                       //obtain the firs word
  while(ifile.eof() == false){         //is the text ended
    check(text);                       //transmit the word to the function
    ifile >> text;                     //going to the next word
  }
  return 0;
}

void check(std::string s){
  int counter{};                   //finding number of vowels literal in a word
  for(size_t i{}; i<s.length(); i++){
    if(counter > 4)
      break;                      //whenever counter was grater than 4 quit the loop
    if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u' || (s[i]<='Z' && s[i]>='A'))                    //conditions that a word woud be wrong
      counter = 0;
    else
      counter++;
  }
  if(counter > 4){
    if(s[s.length()-1] == '.')
      s[s.length()-1] = ' ';
    std::cout << s << std::endl;  //displaying the wrong words
    std::cout << "*********" << std::endl;
  }
}
