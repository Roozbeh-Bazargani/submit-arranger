#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

bool cap(std::string);
std::string charac(std::string);
std::string called(std::string);

int main()
{
	std::ifstream inFile;
	std::string x, text;
	std::string vowels{ "AaEeIiOoUu" };
	inFile.open("Error_find.txt");
	if (inFile)
	{
		while (inFile >> x)
		{
			text = charac(x);	//only returns the alphabets
			if (text.size() < 4)
				continue;
			else if (text.find_first_of(vowels) > 4 && !cap(text))
				std::cout << text << " ";
		}
	}
	else
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}
	std::cout << std::endl;
	return 0;
}

bool cap(std::string s)
{
	for (size_t i{}; i < s.size(); i++)
	{
		if (s[i] < 97 || s[i] > 122)
			continue;
		else
			return false;
	}
	return true;
}

std::string charac(std::string s)
{
	int i{};
	std::string ret;
	while (s[i])
	{
		if (isalpha(s[i]))
			ret += s[i];
		else if (s[i] == '-') {
			ret = called(s);
			break;
		}
		i++;
	}
	return ret;
}

std::string called(std::string s) {		//for words which contains -
	std::string t{};
	size_t n{ s.find_first_of('-') };	//the number of index which contains -
	if (n < 5 && s.size() - n - 1 > 4) {	//for exp. ggg-gggggg which first word is less than 5 chars
		for (size_t i{ n + 1 }; i < s.size(); i++)
			t += s[i];
		return t;
	}
	else if (s.size() - n - 1 < 4 && n > 4) {	//for exp. gggggg-ggg second word is less than 5 chars
		for (size_t i{}; i < n; i++)
			t += s[i];
		return t;
	}

	else if (n < 5 && s.size() - n - 1 < 4) // a correct word
		return "aaa"; //will return a correct word

	else {		//exp. ggggggg-ggggggg two words with more than 5 chars
		std::string first{}, last{};
		for (size_t i{}; i < n; i++)
			for (size_t i{ n + 1 }; i < s.size(); i++)
				last += s[i];
		std::string vowels{ "AaEeIiOoUu" };
		if (first.find_first_of(vowels) > 4 && !cap(first))
			return "bbbbbb";	//means the whole word is wrong so returned a wrong word
		else if (last.find_first_of(vowels) > 4 && !cap(last))
			return "bbbbbb";	//means the whole word is wrong so returned a wrong word
		else
			return "aaa";
	}
}

