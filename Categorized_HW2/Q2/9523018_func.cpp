#include "func.h"


void get_text(std::ifstream& file, std::string& text) {

  char temp{};
  file.open("Error_find.txt");
  file >> std::noskipws;
  while (!file.eof()) {
    file >> temp;
    text += temp;
  }
  file.close();


}


std::vector<std::string> get_words(std::string& text) {

  const std::string separators{ " (),;:.\"!?'\n" }; // Word delimiters
  std::vector<std::string> words; // Words found

  size_t start{ text.find_first_not_of(separators) }; // First word start index
  size_t end{}; // Index for end of a word
  while (start != std::string::npos) // Find the words
    {
      end = text.find_first_of(separators, start + 1); // Find end of word
      if (end == std::string::npos) // Found a separator?
	end = text.length(); // No, so set to last + 1
      words.push_back(text.substr(start, end - start)); // Store the word
      start = text.find_first_not_of(separators, end + 1); // Find 1st character of next word
    }
  std::cout << "Your string contains the following " << words.size() << " words:\n";

  return words;
}


void show_words(std::vector<std::string>& words) {

  size_t count{}; // Number output
  for (const auto& word : words)
    {
      std::cout << std::setw(15) << word;
      if (!(++count % 5))
	std::cout << std::endl;
    }
  std::cout << std::endl;

}


std::vector<std::string> find_wrong_words(std::vector<std::string>& words) {

  std::vector<std::string> bad_words;
  const std::string sep{"aeiouAEIOU"};
  for (size_t i = 0; i < words.size(); i++) {									//checking all words
    if (words[i].length() >= 5) {											
      for (size_t k = 0; k <= words[i].length() - 5; k++) {					//working on > 5 length words it gives their substrs.
	if (chk_vec(bad_words, words[i]))
	  continue;
	std::string temp{ words[i].substr(k, 5) };
	if (temp.find_first_of(sep) == std::string::npos) {
	  if (is_lower(temp))
	    bad_words.push_back(words[i]);
	}
      }

    }
  }
  return bad_words;
}


void show_bad_words(std::vector<std::string>& words) {

  std::cout << "Bad words are here! : " << std::endl;
  std::cout << "---------------------------------------" << std::endl;
  size_t i{};
  size_t count{}; // Number output
  for (const auto& word : words)
    {
      std::cout << std::setw(15) << word;
      if (!(++count % 5))
	std::cout << std::endl;
      i++;
    }
  std::cout << std::endl;
  std::cout << "Number of bad words is : " << std::setw(3) << i << std::endl;

}

bool chk_vec(std::vector<std::string>& v , std::string s) {

  for (size_t i = 0; i < v.size(); i++)
    if (v[i] == s)
      return true;
  return false;
}


bool is_lower(std::string& s) {
  for (size_t i = 0; i < s.length(); i++)
    if (islower(s[i]))
      return true;
  return false;
}
