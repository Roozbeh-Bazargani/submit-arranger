#include <iostream>
#include <string>
#include <stack>

void selection_sort(double*, size_t );

int main()
{
	double input{};
	std::stack<double> nums{};
	std::cout << "Enter a number ( 0 to exit) :\n";
	std::cin >> input;

	while (input != 0)
	{
		nums.push(input);
		std::cout << "Enter next number ( 0 to exit) :\n";
		std::cin >> input;
	}
	size_t size{ nums.size() };
	double* arr{ new double[size] {} };

	for (size_t i = 0; i < size; i++)
	{
		arr[i] = nums.top();
		nums.pop();
	}

	selection_sort(arr, size);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	std::cout<<std::endl;
	return 0;
}

void selection_sort(double* arr, size_t size)
{
	double temp{};
	for (size_t i = 0; i < size-1; i++)
	{
		size_t min{ i };
		for (size_t j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}

		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;

	}


}
