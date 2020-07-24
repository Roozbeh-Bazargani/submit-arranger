#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include <vector>

int main()
{
  std::string text{};
  std::ifstream myfile("Error_find.txt");
  int cnt{};
  bool cap{};
  if (myfile.is_open()) //checking the file can be read
    {
      std::vector<std::string> ans{}; // for storing the answers
      while (std::getline(myfile, text)) // reading file
	{
	  // finding words
	  const std::string separators{ " ,;:.\"!?'\n()" }; //seperating chars
	  std::vector<std::string> words{};
	  size_t start{ text.find_first_not_of(separators) };
	  size_t end{};
	  while (start != std::string::npos)
	    {
	      end = text.find_first_of(separators, start + 1); // Find end of word
	      if (end == std::string::npos) // Found a separator?
		end = text.length(); // No, so set to last + 1
	      words.push_back(text.substr(start, end - start)); // Store the word
	      start = text.find_first_not_of(separators, end + 1); //Find 1st character of next word
	    }
	  for (const std::string& word : words) // checking dictation
	    {
	      if (word.size() > 4)
		{
		  for (size_t i{}; i < word.size(); i++)
		    {
		      if ((int(word[i]) > 96) & (int(word[i]) < 123)) // Lower
			{
			  cnt++;
			  cap = true;
			}
		      else if ((int(word[i]) > 64) & (int(word[i]) < 91)) // Uper
			{
			  cnt++;
			}
		      else // some chars like _ - 
			{
			  cnt = 0;
			  cap = false;
			}
		      if (word[i] == 'a' || word[i] == 'A' 
			  || word[i] == 'e' || word[i] == 'E'
			  || word[i] == 'o' || word[i] == 'O'
			  || word[i] == 'u' || word[i] == 'U'
			  || word[i] == 'i' || int(word[i]) == 'I')
			{
			  cnt = 0;
			  cap = false;
			}

		      if ((cnt == 5) & cap) // checking dictation
			{
			  ans.push_back(word); // storing the word
			  break;
			}
		    }
		  cnt = 0;
		  cap = false;
		}
	    }
	}
      // Printing output
      size_t count{}; // Number output
      for (const std::string& a : ans)
	{
	  std::cout << std::setw(15) << a;
	  if (!(++count % 5))
	    std::cout << std::endl;
	}
      if (count % 5)
	std::cout << std::endl;
    }
  else // problem in reading text file
    std::cout << "Unable to open file\n";
  myfile.close();

  return 0;
}

