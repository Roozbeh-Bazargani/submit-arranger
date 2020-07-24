//
//  main.cpp
//  Q2
//
//  Created by kian behzad on 12/6/1396 AP.
//  Copyright © 1396 AP kian behzad. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


bool readthefile(std::string filename, std::vector<std::string>& words);
bool iscorrect(std::string word);
bool check_5_consonant_in_row(std::string word);


int main(int argc, const char * argv[]) {
    
    //reading the file and parsing the text
    std::vector<std::string> words;
    if(!readthefile("Error_find.txt", words))
        return 0;
    
    //checking the words ands save the wrong ones
    std::vector<std::string> wrongs;
    for(const auto& word : words)
        if(!iscorrect(word))
            wrongs.push_back(word);
    
    //printing the wrong words
    std::cout << "the detected wrong words are as follow: " << std::endl;
    for(const auto& wrong : wrongs)
        std::cout << ">" << wrong << std::endl;
    
    

    
    
    
    
        return 0;
}



bool readthefile(std::string filename, std::vector<std::string>& words)
{
    std::ifstream file(filename);
    if(!file)
    {
        std::cout << "there's no such file as" << filename << std::endl;
        return false;
    }
    std::string text;                                                                               // The string to be searched
    std::string temp;
    while(!file.eof()) {
        getline(file, temp);
        text += temp + "\n";
        
    }
    const std::string separators{ " (),;:.\"!?'\n" };                                               // Word delimiters
    size_t start { text.find_first_not_of(separators) };                                            // First word start index
    size_t end {};                                                                                  // Index for end of a word
    while (start != std::string::npos)                                                              // Find the words
    {
        end = text.find_first_of(separators, start + 1);                                            // Find end of word
        if (end == std::string::npos)                                                               // Found a separator?
            end = text.length();                                                                    // No, so set to last + 1
        words.push_back(text.substr(start, end - start));                                           // Store the word
        start = text.find_first_not_of(separators, end + 1);                                        // Find 1st character of next word
    }
    return true;
}



bool iscorrect(std::string word)
{
    return check_5_consonant_in_row(word);
}



bool check_5_consonant_in_row(std::string word)
{
    bool isinitial = true;
    int  consonant_cnt{};
    for(const auto& test : word)
    {
        if(test != 'a' && test != 'e' && test != 'i' && test != 'o' && test != 'u' && test != 'A' && test != 'E' && test != 'I' && test != 'O' && test != 'U')
            consonant_cnt++;
        else
            consonant_cnt = 0;
    }
    if(consonant_cnt >= 5)
    {
        for(const auto& captest : word)
            if( !(captest <= 90 && captest >= 41))
                isinitial = false;
        if(isinitial)
            return true;
        if(!isinitial)
            return false;
    }
    return true;
}


