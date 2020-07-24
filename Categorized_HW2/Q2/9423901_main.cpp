#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;

int main()
{
  string filename {"Error_find.txt"}; // Input file name
  std::ifstream inFile {filename}; // Create input stream object
  
  // Make sure the file stream is good
  if (!inFile)
    {
      std::cout << "Failed to open file " << filename << std::endl;
      return 1;
    }
  
  std::vector<string> words;
  string word;
  
  while (true)
    {                                    
      inFile >> word; // Read a value from the file
      if (inFile.eof()) // Continue until EOF is found
	break;
      words.push_back(word);
    }
 inFile.close(); // Close the input stream

 int counter{};
 for(unsigned int i{} ; i < words.size() ; i++) // Find wrong words
   {
     for(unsigned int j{} ; j < words[i].length() ; j++)
       {
	 if( ((words[i][j] >= 'a') && (words[i][j] <= 'z')) || ((words[i][j] >= 'A') && (words[i][j] <= 'Z')) )
	   {
	     if(words[i][j] != 'a' && words[i][j] != 'A' && words[i][j] != 'e' && words[i][j] != 'E' &&
		words[i][j] != 'o' && words[i][j] != 'O' && words[i][j] != 'u' && words[i][j] != 'U' &&
		words[i][j] != 'i' && words[i][j] != 'I')
	       counter++;
	     else
	       counter = 0;
	   }
	 else
	     words[i].erase(j);
       }
     if(counter >= 5) // Print wrong word
       std::cout << words[i] << std::endl;
     counter = 0;
   }
 return 0;
}
