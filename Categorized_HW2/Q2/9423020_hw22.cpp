#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
string errorText;
string temp;
ifstream errorFile("Error_find.txt"); 
while(getline(errorFile, temp)) //getting the string file line by line
{
	errorText += temp; //storing it all in a string
}
vector<string> words;
const string separators{"() ,;:.\"!?'\n"}; //to locate the words
size_t start{ errorText.find_first_not_of(separators)}; 
//the index of first word
size_t end{};

while(start != string::npos)
{
	end = errorText.find_first_of(separators, start + 1);
	if (end == string::npos)
	{
	   end = errorText.length();
	}
	words.push_back(errorText.substr(start, end - start));
	start = errorText.find_first_not_of(separators, end + 1);
}
for(const auto& word : words)
{  
	string uppercases{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string numbers{"0123456789"};
	size_t vowel{};
	 size_t numberofuppers{};
	size_t numberofNumber{};
	string vowels{"aeyiuo"};
	vowel = word.find_first_of(vowels);
	if(vowel == string:: npos)
	{ 
	  numberofNumber = word.find_first_not_of(numbers);
	  numberofuppers = word.find_first_not_of(uppercases); 
	  if(numberofNumber != string::npos && numberofuppers !=  string::npos)
		cout << word <<endl;
	}

}
cout << endl;

return 0;

}
