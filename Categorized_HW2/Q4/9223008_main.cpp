/******NAHID ETESAMI 9223008******/
/**********Selection Sort*********/


#include <iostream>
#include <vector>

int main()
{
	//Using Vector to be able to increase the lenght of array:
	std::vector<int> a; 
	int N{}; //N will be the index of array
	int g{}; //Temporary variable - will be used to get the numbers

	std::cout << "Enter The numbers you want to be sorted, enter 0 to terminate:"
	<< std::endl;
	

	//Getting values:
	do {
	std::cout <<"Enter a[" << N << "]: ";
	std::cin >> g ; 
	a.push_back(g); 
	N++;
	} while ( g != 0 );


	std::cout << std::endl << "Sorted values:" << std::endl ;


	//Selection Sorting:
	int min{}, k{};
	for (int j{} ; j < N - 1 ; j++ )
	{
		min = a[j];
	
		for( int i = j + 1 ; i < N ; i++ )
			if (a[i] < min)
			{
				k=i;
				min = a[i];
				a[k] = a[j];
				a[j] = min;	
			}
	}


	//printing sorted values:
	for (int j{1} ; j < N ; j++ )
		std::cout<<a[j]<<std::endl;


	return 0;
}
