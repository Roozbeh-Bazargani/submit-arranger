#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

int main(){
  int k{};
  std::vector < std::string > v;
  std::string str;
  std::ifstream myfile("Error_find.txt");
  while( myfile >> str)
  {
    v.push_back(str); // this will change a text character by character to string    
  }
 myfile.close();
;
 
 std::cout << "list of wrong words: " << std::endl;	

 for(size_t i{}; i < v.size() ; i++){ //checking words by words

   std::string word = v[i];

   
    if( word.length() > 4){
      

     for(size_t j{}; j < word.length() ; j++){
       if( int( word[j]) >96){
	 if(word[j] != 'a' && word[j] != 'e' && word[j] != 'i' &&  word[j] !='o' &&  word[j] !='u')
	  k++;
	else
	  k=0;
       }
     }
	    
     if(k > 4)
    std::cout << v[i]<< std::endl;
    }
 }

return 0;

}



























