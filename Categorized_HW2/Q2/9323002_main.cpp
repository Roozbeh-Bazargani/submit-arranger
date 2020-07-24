#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    const std::string separators{ " ,();-:.\"!?'\n" };//word separators

    int counter{0};//consonant counter

    std::string STRING{};//text file article
    std::string placeHolder{};//line string

    std::vector<std::string> words;//a vector for save all words in article
    std::vector<std::string> wrongWords;//wrong word in article

    std::ifstream infile;
    infile.open ("Error_find.txt");//open text file

    while(!infile.eof()) // To get you all the lines.
    {
        getline(infile, placeHolder); // Saves the line in placeHolder.
        STRING += placeHolder; //add line in STRING
    }

    infile.close();//close text file

    size_t start { STRING.find_first_not_of(separators) };// First word start index
    size_t end {};// Index for end of a word

    while (start != std::string::npos)
    // Find the words
    {
        end = STRING.find_first_of(separators, start + 1);// Find end of word
        if (end == std::string::npos)// Found a separator?
            end = STRING.length();
        words.push_back(STRING.substr(start, end - start));// Store the word
        start = STRING.find_first_not_of(separators, end + 1); // Find 1st character of next word
    }



    for (const auto& word : words)//for loop for check every word
    {
        int length = word.length();//word length
        for (int h{0}; h < length; h++) {//variable h present the index of the word letter
            switch (word[h]) {
                case 'a': //vowels case
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A': //vowels case
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    counter = 0;//every vowel set counter to 0
                    break;
                default:
                    ++counter;
                    if (counter == 5){
                        wrongWords.push_back(word);//for 5 constant letter we push the word in wrong word list
                    }
                    break;
            }
        }

        counter = 0;//after checking any word set counter to 0

    }
    for (const auto& wrongWord : wrongWords) {
        if( std::any_of( wrongWord.begin(), wrongWord.end(), isupper )) { //check that the word is not all uppercase

        }
        else{
            std::cout << wrongWord << std::endl; //print the word
        }
    }
    std::cout << std::endl;


    return 0;
}

