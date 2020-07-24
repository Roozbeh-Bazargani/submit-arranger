#include <string>
#include <regex>
#include <fstream>
#include <iostream>

using namespace std;
using namespace regex_constants;

int main()
{
	smatch match;
	ifstream inFile;
	string line;
	string name = "Error_find.txt";
	
	inFile.open(name);

	if (!inFile)
	{
		cerr << "Unable to open file " + name << endl << "press any key...";
	getchar();
	return 0;
	}
	regex e(R"(\b[^\s\-A-Zaeiyou]{5,}\b)");

	while (getline(inFile, line))
	{
		while (regex_search(line, match, e)) 
		{
			for (string x : match)
				cout << x << endl;
		
			line = match.suffix().str();	
		}	
	}
	inFile.close();
	getchar();

	return 0;
}
