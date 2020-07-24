//find small letter acronyms.
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>

int main()
{
  std::cout << "Please put your txt file in the main.cpp directory." << std::endl;
  std::cout << "Please Enter the name of txt file with .txt index: " << std::endl;
  std::string filename{};
  std::cin >> filename;
  std::string txt{};
  const std::string seprators{" ().\n,;:?!"}; //New word starts after these characters. 
  const std::string seprators2{"0123456789AaUuOoIiEeBCDEFGHJKLMNPQRSTVWXYZ"}; //if a word contains these chars, it can not be an acronym.
  std::vector<std::string> words; //store words of a txt in a vector.
  std::ifstream ifile{filename};
  if(!ifile){  //is there a txt file with the name whitch user entered? 
    std::cout << "couldn't find this file!" << std::endl;
    return 1;
  }
  while(!ifile.eof()){    //get the txt file line by line
    getline(ifile, txt);
    size_t start{txt.find_first_not_of(seprators)}; //first word start index
    size_t end{}; //index for end of the word
    while(start != std::string::npos){ //find the words
      end = txt.find_first_of(seprators,start + 1); //find end of word
      if(end == std::string::npos) //found a seprator?
	end = txt.length();//if not go forward
      words.push_back(txt.substr(start, end - start));//store the word
      start = txt.find_first_not_of(seprators, end + 1);//find the first char of next word
    }
  }
  ifile.close();
  // Error finding
  std::cout << "acronym mistakes: " << std::endl;
  for(size_t i = 0; i <= words.size(); i++){ //checking word by word
    if((words[i]).length() >= 5){//error will occur for words with more than 5 letters.
      size_t start2{words[i].find_first_of(seprators2)};//which of words have seprators?
      if(start2 >= 5)//we have seprator after 5 letters.
	std::cout << words[i] << std::endl;
    }
  }
  return 0;
}

