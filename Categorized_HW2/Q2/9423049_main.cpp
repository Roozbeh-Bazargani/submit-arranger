#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib> 
int main(){
  int n{0};
  int l{0};
 std::ifstream ifile("Error_find.txt");
 if(!ifile){
   std::cout<<"ERROR,file is'nt found."<<std::endl;
   exit(1);
     }
 std::string text, tmp; // The string to be searched
 while(std::getline(ifile, tmp))
   text += tmp + '\n';
   
 ifile.close();
 
const std::string separators{ " ,;:.\"!?'\n ()" }; // Word delimiters
std::vector<std::string> words;  // Words found
 
size_t start { text.find_first_not_of(separators) };

size_t end {};   // Index for end of a word
 
 while (start != std::string::npos) { // Find the words
  end = text.find_first_of(separators, start + 1);
  // Find end of word
  if (end == std::string::npos) // Found a separator?
   end = text.length();  // No, so set to last + 1
   words.push_back(text.substr(start, end - start));
   start = text.find_first_not_of(separators, end + 1);
 }

 for(size_t i{} ; i < words.size()-1 ;++i){
  std::string test;
  test=words[i];
  if (test.size() > 4){
    n=0;
    l=0;
    for(size_t j {} ; j<test.size() ; ++j){
      if(std::isupper(test[j]))// Check for a letter
	continue;
      else{
        switch(std::tolower(test[j])){// Convert to lowercase

      case 'a': case 'e': case 'i': case 'o': case 'u':
	 l++;
         break;
      default:
	n++;
	break;}
      
      if(l>=1) break;
      if(n>4){
     	std::cout<<test<<std::endl;
	break;}
      }
    }
  }
 }    
 return 0;}

