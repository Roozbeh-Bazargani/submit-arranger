#include<iostream>
#include<vector>


int main()
{
	double a;
	std::vector<double> arr, arr_in;
	std::cout << "Please enter your numbers and 0 for ending" << std::endl;

	//inserting numbers in an array
	while (std::cin >> a) {
		if (a == 0) {
			std::cout << "Ended" << std::endl;
			break;
		}
		else
			arr.push_back(a);
	}

	arr_in = arr;//save the initial value


	double temp{};
	size_t n{}, min{};
	n = static_cast<size_t>(arr.size());//arr.size is long unsigned int


	for (size_t i{}; i < n - 1; i++)
	{
		min = i;//set min to the current index of array

		for (size_t j{ i + 1 }; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		//swaping the values in case if they changed
		//swaping the current index and the min
		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	std::cout << "Entered numbers: ";
	for (size_t i{}; i < n; i++)
		std::cout << arr_in[i] << " ";
	std::cout << "\nSorted numbers:  ";
	for (size_t j{}; j < n; j++)
		std::cout << arr[j] << " ";
	std::cout << std::endl;

	return 0;
}

