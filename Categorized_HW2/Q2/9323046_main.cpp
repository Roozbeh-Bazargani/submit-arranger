//Created By Mohammad Sadegh Safari 9323046

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

int main()
{
  std::ifstream ifile{"Error_find.txt"};

  //Checking File Existance
  if(!ifile) {
    std::cout << "not found" << std::endl;
    return 1;
  }

  //Defining Vector For Storing Words And
  std::vector<std::string> text;

  //Reading first word
  std::string wrd{};
  ifile >> wrd;

  //reading words ans storing them in a vector
  while(!ifile.eof()) {
      text.push_back(wrd);
      ifile >> wrd;
  }
  
  size_t consonant{},index{};
  int begin{-1};

  //processing words one by one
  for(auto word:text){
    consonant = 0;
    begin = -1;

    //checking word characters one by one
    for(size_t i{}; i < word.size(); i++) {

      //checking curent char is vowel or consonant
      if(word[i]== 'a' || word[i]== 'e' ||word[i]== 'i'|| word[i] == 'o'
	    || word[i] == 'u' || word[i] == 'A' ||word[i]== 'E'
	    || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
	  consonant = 0;
	  begin = i;
      }
      else if( (word[i] >= 'a' && word[i] <= 'z')
		 || (word[i] >= 'A' && word[i] <= 'Z') ) {
	  consonant++;
	}
      else {
	  consonant = 0;
	  begin = i;
	}

      //checking 5 consonants are beside each other or not
      if(consonant == 5) {
	bool abbr{true};

	//checking that curent word is abbreviation or not
	for(int j{begin+1}; j < begin+6; j++){

	  if( !(word[j] >= 'A' && word[j] <= 'Z')){
	    abbr = false;
	    break;
	  }

	}

	if(!abbr){

	  while((index = word.find_first_of("!().?[]{}")) !=std::string::npos) {
	    word.erase(index,1);
	  }

	  //print word if it is incorrect
	  std::cout << word <<  std::endl;
	  break;
	}
	
      }
      
    }
    
  }
  
  return 0;
}
