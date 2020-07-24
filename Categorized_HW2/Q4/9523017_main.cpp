//
//  main.cpp
//  Q4
//
//  Created by kian behzad on 12/7/1396 AP.
//  Copyright © 1396 AP kian behzad. All rights reserved.
//


#include <iostream>
#include <vector>

void section_sort(std::vector<float>& numbers);
void display(const std::vector<float>& numbers);
void swap(float& a, float& b);

int main(int argc, const char * argv[]) {
    
    std::vector<float> numbers;
    float tempnum{};
    std::cout << "please enter your number array:(zero means numbers are finished)" << std::endl;
    while(true)
    {
        std::cin >> tempnum;
        if(tempnum == 0)
            break;
        numbers.push_back(tempnum);
    }
    

    section_sort(numbers);
    
    display(numbers);
    
    
    return 0;
}

void section_sort(std::vector<float>& numbers)
{
    size_t index{};
    for(size_t j{}; j < numbers.size() - 1; j++)
    {
        index = j;
        for(size_t i{j}; i < numbers.size(); i++)
        {
            if(numbers[i] <= numbers[index])
                index = i;
        }
        swap(numbers[j], numbers[index]);
    }
}

void display(const std::vector<float>& numbers)
{
    std::cout << "> " << std::endl;
    for(const auto& num : numbers)
        std::cout << num << "   ";
    std::cout << std::endl;
}

void swap(float& a, float& b)
{
    float c{a};
    a = b;
    b = c;
}

