#include<iostream>
#include<cmath>

using std::cin;
using std::endl;
using std::cout;

void selectionSort(double* arr,size_t N);

int main(){
  size_t j{};
  double num{1};
  size_t N{500};
  double* arr;
  arr = new double[N];
  //it takes numbers until 0 is entered
  cout<<"enter a  number, 0 is equal to end of program"<<endl;
	while(num ){
	  cin >> num;
	  arr[j] = num;
          j++;
	}
    cout<<"Sorted elements are:"<<endl; 
    selectionSort(arr , j--);
}
//selection sort function
// this function calculates the smallest element's place in array
//and puts the first element in a temperory variable. the smallest
//variable's place will change with the first elemnt and temperory
// would be in place of smallest.
void selectionSort(double* arr,size_t N){

  size_t small{};
  double temp{};
  for (size_t i{}; i< N ; i++){
    small = i;
    for (size_t j{i+1}; j < N; j++){
      if(arr[j] < arr[small])y
	small = j;
    }
    if (small != i){
      temp = arr[i];
      arr[i] = arr[small];
      arr[small] = temp;
    }
    cout<<arr[i]<<endl;
      }

}
