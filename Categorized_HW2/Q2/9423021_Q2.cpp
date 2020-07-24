#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

using std::string;

int main()
{
  string text; // The string to be searched
  std::ifstream txtFile ("Error_find.txt"); //Gets the input file Error_find.txt in txtFile
  getline(txtFile,text , (char) txtFile.eof()); // Saves the lines in text string
  const string separators{ " ,;:.\"!?'\n)(" }; // Word delimiters
  std::vector<string> words; // Words found
  size_t start { text.find_first_not_of(separators) }; // First word start index
  size_t end {}; // Index for end of a word

  while (start != string::npos) // Find the words
    {
     end = text.find_first_of(separators, start + 1); // Find end of word
      if (end == string::npos) // Found a separator?
	end = text.length(); // No, so set to last + 1
      words.push_back(text.substr(start, end - start)); // Store the word
      start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
    }
  for (size_t i{}; i < words.size() ; i++)
    {
      size_t uppCount{}, conCount{}; //Upper letters counter and consonant letter counter
      if (words[i].size() > 4){ //Don't bother if the word has less than 5 letters
	for (size_t iL{}; iL < words[i].size() ; iL++)
  	       {
  		 if (std::isupper(words[i][iL])) //if letter is Upper count + 1
  		     uppCount++; 

		 switch (words[i][iL]) { //if letter is a vowel count the consonant from 0 again
		 case 'a': case 'e': case 'i': case 'o': case 'u':
		 case 'A': case 'E': case 'I': case 'O': case 'U':
		   conCount = 0; break;
		 default: conCount++; break; //if letter is not a vowel consonant count +1
		 }

  		 if (uppCount == words[i].size()) //if all letters were upper it's abbreviation
  		   conCount = 0;
  	       }
      }
      //now if there were more than consonant show the word as error
  		 if (conCount > 4)
  		   std::cout << words[i] << " " ;
  		 uppCount = 0;
  		 conCount = 0;
    }
  std::cout << std::endl;
 
 }
