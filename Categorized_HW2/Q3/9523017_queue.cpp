//
//  queue.cpp
//  Q3
//
//  Created by kian behzad on 12/7/1396 AP.
//  Copyright © 1396 AP kian behzad. All rights reserved.
//

#include "queue.hpp"

Queue::Queue(std::string filename)
{
    //read the file
    std::ifstream file(filename);
    if(!file)
    {
        std::cout << "there's no such file as" << filename << std::endl;
        gotthefile = false;
    }
    else
        gotthefile = true;
    
    //parsing the file into string
    if(gotthefile)
    {
        std::vector<std::string> words;
        std::string text;                                                                               // The string to be searched
        std::string temp;
        while(!file.eof()) {
            getline(file, temp);
            text += temp + "\n";
            
        }
        const std::string separators{ " (),;:\"!?'\n" };                                               // Word delimiters
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
        
        //assign the parsed strings into the desired position
        queueSize = static_cast<size_t>(::atoi(words[0].c_str()));
        words.erase(words.begin() + 0);
        queue = new float[queueSize];
        int cnt{};
        for(const auto& word : words)
        {
            if(isFloat(word))
                queue[cnt++] = ::atof(word.c_str());
            else
                gotthefile = false;
        }
        
        //setup writer, reader, freespace
        writer = static_cast<int>(words.size() - 1);
        reader = -1;
        freeSpace = (writer > reader) ? (queueSize - (writer - reader)) : reader - writer;
    }
}



void Queue::displayQueue()
{
    if(gotthefile)
    {
        std::cout << "> ";
        if(writer > reader)
            for(int i{reader + 1}; i <= writer; i++)
            {
                if(i == writer)
                    std::cout << queue[i] << std::endl;
                else
                    std::cout << queue[i] << ", ";
            }
        if(writer == reader)
            std::cout << "[WARNING]the Queue is empty" << std::endl;
        if(writer < reader)
        {
            for(int i{reader + 1}; i < static_cast<int>(queueSize); i++)
                std::cout << queue[i] << ", ";
            if(writer != -1)
                for(int i{0}; i <= writer; i++ )
                {
                    if(i == writer)
                        std::cout << queue[i] << std::endl;
                    else
                        std::cout << queue[i] << ", ";
                }
        }
    }
    else
        std::cout << "there's no such file" << std::endl;
}



void Queue::enQueue(float num)
{
    if(gotthefile)
    {
        if(freeSpace != 0)
        {
            writer++;
            if(writer == static_cast<int>(queueSize + 1))
                writer = 0;
            freeSpace = (writer > reader) ? (queueSize - (writer - reader)) : reader - writer;
            queue[writer] = num;
        }
        else
            std::cout << "[WARNING]cannot add " << num << " to your queue : no free spaces" << std::endl;
    }
    else
        std::cout << "there's no such file" << std::endl;
}



float Queue::deQueue()
{
    if(gotthefile)
    {
        if(freeSpace != queueSize)
        {
            reader++;
            if(reader == static_cast<int>(queueSize + 1))
                reader = 0;
            freeSpace = (writer > reader) ? (queueSize - (writer - reader)) : reader - writer;
            return queue[reader];
        }
        else
            std::cout << "[WARNING]cannot deQueue your queue : no elements found" << std::endl;
    }
    else
        std::cout << "there's no such file" << std::endl;
    return 1274623e12;
}


bool Queue::isFloat( std::string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

