#include <iostream>
#include <vector>
#include <cmath>


int main()
{
    int placeHolder{}; //placeholder for input

    std::vector<int> numbers{};//input numbers

    while(std::cin >> placeHolder) { //get inputs and push them in vector and finish with 0
        if(placeHolder == 0) break;
        numbers.push_back(placeHolder);
    }

    int vectorSize = numbers.size(); //vector size
    int tmp{}; //placeholder for temporary number in sorting

    std::cout << "your numbers numbers:" << std::endl;

    for( int i = 0; i < vectorSize; i++)  //print the user inputs in a line
        std::cout << numbers[i] << " ";

    std::cout << std::endl;

    for (int i = 0; i < vectorSize; i++)

        for (int j = i+1; j < vectorSize; j++)

            if (numbers[i] > numbers[j])
            {
                tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }

    std::cout << "sorted numbers:" << std::endl;

    for( int i = 0; i < vectorSize; i++) //print sorted numbers
        std::cout << numbers[i] << " ";

    std::cout << std::endl;
    return 0;

}

