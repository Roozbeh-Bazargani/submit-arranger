#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>
#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		std::cout << arr[]
}
// Driver program to test functions
int main()
{
      int a{};
      std::cout << "enter 0 to continue." << std::endl;
      std::cin >> a;
      int num{};
      int N{};
      int i{};
      int* arr{new int[N]};
      while(a == 0){
         std::cout << "enter ur No. : " << std::endl;
         std::cin >> num;
         arr[i] = num;
         i++;
         std::cout << "ur No. is: " << num << std::endl;
         std::cout << "enter 0 to continue" << std::endl;
         std::cin >> a;
          } 
     selectionSort(arr, i);
     std::cout << "Sorted Array: " << std::endl;
     printArray(arr, i);
     return 0;
}
