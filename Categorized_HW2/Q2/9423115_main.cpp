/* M.Mehdi Naseri 9423115 */

#include<iostream>
#include<string>
#include<fstream>

bool isSilent(char& c);
bool isMistake(std::string& word);

int main() 
{
    std::ifstream inFile;
    inFile.open("Error_find.txt"); //open txt file
    if (!inFile) 
    {
        std::cout << "ERROR: Unable to open file" << std::endl; //unable to open txt file
        return 1;
    }

    std::string word{};
    while (inFile >> word) //for every word
        if(isMistake(word))
        {
        	for(char c : word)
        		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) //do not print nonAlphabet characters
        			std::cout << c;
        	std::cout << " ";
        }
    
    std::cout << std::endl;

    inFile.close(); //close the file
    return 0;
}

bool isMistake(std::string& word)
{
	unsigned int silentCounter{0};

	for(char c : word)
	{
		if(isSilent(c))
		{
			silentCounter += 1;
			if(silentCounter == 5)
				for(char cprime : word)
					if(cprime >= 'a' && cprime <= 'z')
						return true; //if there is at least one lower case and 5 continuous silent characters
		}
		else
			silentCounter = 0;
	}

	return false;
}

bool isSilent(char& c)
{
	switch(c)
	{
    case 'a' : return false;
    case 'A' : return false;
    case 'e' : return false;
    case 'E' : return false;
    case 'i' : return false;
    case 'I' : return false;
    case 'o' : return false;
    case 'O' : return false;
    case 'u' : return false;
    case 'U' : return false;
	}

	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	return false;
}