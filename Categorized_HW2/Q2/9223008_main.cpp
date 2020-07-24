/******NAHID ETESAMI 9223008******/
/**********Selection Sort*********/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool SymbolCheck ( char c );
bool capit(std::string str);
bool VowelCheck(std::string str);

int main()
{
	std::string s{};
	std::ifstream TestText{"Error_find.txt"}; //importing the text
	int StringLenght{};


	
	while ( !TestText.eof ()  )
	{
		TestText >> s ;
		if ( TestText.eof ()  )
			break;

		StringLenght= s.length();


		//removing symbols:
		char Symbols[]{"( ) - , ."};
		for (int i = 0 ; i < StringLenght + 3 ; i++ )
			s.erase ( std::remove(s.begin(), s.end(), Symbols[i]), s.end () );

		//checking if the word is written wrong:
		if ( ( StringLenght > 4 ) 
			&& ( capit(s) == 0 )
			&& ( VowelCheck(s) == 1 ) )
			std::cout << s << std::endl ;

			
	}	

	TestText.close();
	std::cout << std::endl;	
	
	return 0;
}



//function to find out if a word's alphabet are all capital
bool capit (std::string str)
{
	size_t sum{};

	for (size_t i{} ; i <= str.length() ; i++ )	
		{
		if ( str[i] >= 'A' && str[i] <= 'Z' )
				sum++;
		else
			break;
		}

	
	if ( sum == str.length() )
		return true;
	else
		return false;

}


//function to check if there are more than 4 consonants without a vowel
bool VowelCheck(std::string str)
{
	int sum{};
	
	for (size_t i{} ; i < str.length() ; i++ )
	{
		if ( (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') 
		|| (str[i] == 'o') || (str[i] == 'u') || (str[i] == 'A')
		|| (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O')
		|| (str[i] == 'U'))
			sum = 0;

		else
		{
			sum++;
			if ( sum >= 5 )
			{		
				return true;
			}
			
		}
	}

	return false;

}



