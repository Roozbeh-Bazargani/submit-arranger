
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "func.h"



int main()
{	
	std::ifstream file;
	std::string text{};
	std::vector<std::string> words;
	std::vector<std::string> bad_words;


	get_text(file, text);	//makes the string text from file

	words = get_words(text);	//find words using book algorythm
	show_words(words);	//show words in a table

	bad_words = find_wrong_words(words);
	std::cout << std::endl;
	show_bad_words(bad_words);

    return 0;
}


