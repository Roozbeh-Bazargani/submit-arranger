//By Navid Hasanzadeh 9323701
//HW2 - Q2
#include<iostream>
#include<string>
#include<fstream>
#include"english.h"

using std::string;

int main(){
	string txtAddress;
	string wrongWords;
	char wordTemp[5];
	short int ConsonantNum = 0;
	short int upperCaseNum =0;	
	char currentChar;
	// Define file input stream
	std::ifstream myTextFile;
	// Address of the file
	txtAddress = "Error_find.txt";
	//Open the text file
	myTextFile.open(txtAddress);
	// Read the text file until it finish
	if (myTextFile.is_open())
	{
		while (!myTextFile.eof())
		{
			// Read the text character by character, noskipws is used 
			//  to include space and enter in characters
			myTextFile >> std::noskipws >> currentChar;
			// find words with the 5 consonant letters
			if (isConsonant(currentChar)){
				ConsonantNum ++;
				wordTemp[ConsonantNum-1] = currentChar;
				//Check the letter for uppercase						
				if(isUpperCase(currentChar)){
					upperCaseNum ++;
				}
				// if all 5 Consecutive letters are consonant, the word might be a wrong word.
				if (ConsonantNum==5){
				// check if all 5 consecutive  letters are uppercase or not	
					if(upperCaseNum < 5){
						// add the word to wrong words list.
						string str{wordTemp};
						wrongWords += str + " ";
						}
					upperCaseNum = 0;
					ConsonantNum = 0;
				}
			}
			else{
				upperCaseNum = 0;
				ConsonantNum = 0;
			}
			// print the text characters.
			std::cout << currentChar;
		}
	}
	// print all the wrong words.
	std::cout << wrongWords << std::endl;
	return 0;
}

