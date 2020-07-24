#include<iostream>
#include<cmath>

void swap(double, double);
// exchange the  amount of two variables
void selection_sort(double arr[] ,int n );
//sort an array by comparing two elemnts of array
void printArray(double arr[] , int n );
//printing elements of an array

int main(){
  double arr1[1000]; // defining an array for saving numbers that user enters
  int n{};
  double num{};
  std::cout <<"enter the elements of your array to sort , at the end please enter zero to finish this step" << std::endl;
  while(true){
    std::cin >> num;
    if(num==0)
      break;
    else{
    arr1[n]= num;
    n++;
    }
  }
  double* arr{new double(n)}; // defining a dynamic array for saving entered numbers in it
  delete[] arr; //deleting dynamic array for use the memory again
 
  for (int j{} ; j< n  ; j++){
      arr[j] = arr1[j];
  }
  selection_sort(arr, n); //calling selection sort function to sort array's elements
  std::cout <<" sorted array is:" << std::endl;
  printArray(arr , n); // displaying sorted  array elements 
 
  return 0;
} 

void swap(double *x  , double *y)//exchange the  amount of two variables
{
  double temp {};
  temp = *x;
  *x = *y;
  *y = temp;
}
void selection_sort(double arr[] ,int n )//sort an array by comparing two elemnts of array
{
  int i, j, min_index;
  for (i = 0; i < n-1; i++){
      min_index= i;
      for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_index])
min_index = j;

// Swap the found minimum element with the first element
swap( &arr[min_index], &arr[i]);
     
  }
}


void printArray(double arr[], int n )//printing elements of an array
{
int i;
for (i=0; i < n ; i++)
  std::cout << arr[i] <<"\n" << std::endl;
}

