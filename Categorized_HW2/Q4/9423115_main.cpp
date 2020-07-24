/* M.Mehdi Naseri 9423115 */

#include<iostream>
#include<vector>

int main() 
{
    double num{};
    std::vector<double> number;
    std::cout << "Enter your numbers (0 for finish): " << std::endl;
    std::cin >> num;

    /* Cin numbers */
    while(num != 0)
    {
    	number.push_back(num);
    	std::cin >> num;
    }

    if(number.size() > 0)
    {
    	/* Sorting */
    	for(size_t i{0}; i < number.size() - 1; i++)
	    {
	    	/* Find minimum */
	    	double minimum = number[i];
	    	size_t minimumIndex = i;
	    	for (size_t j{i + 1}; j < number.size(); j++)
	    	{
	    		if(number[j] < minimum)
	    		{
	    			minimum = number[j];
	    			minimumIndex = j;
	    		}
	    	}

	    	/* Swap */
	    	number[minimumIndex] = number[i];
	    	number[i] = minimum;
	   	}
	   	/* Print */
	   	std::cout << "Sorted Array: ";
	    for(size_t i{0}; i < number.size(); i++)
	    {
	    	std::cout << number[i] << " ";
	    }
	    std::cout << std::endl;
    }
    else
    {
    	std::cout << "You didn't enter any number..." << std::endl;
    }

   	return 0;
}
