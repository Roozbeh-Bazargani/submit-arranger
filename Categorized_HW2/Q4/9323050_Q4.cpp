#include<iostream>

int main()
{
  int i{};//i declare the step number
  int N{};//N declare the size of the array that varies each time
  int* arr{new int [N]};//a dynamic array for saving the entered numbers
  int num{1};//initialize num with 1 so it can enter the while loop
  
  while(num != 0)
    { 
      std::cout<<"enter a number:"<<std::endl;
      std::cin>>num;
      if(num != 0)
	{
	  N++;//increasing the dynamic array capacity
	  arr[i]=num;
	  i++;
	}
    }
  //user enters 0 so we are out of the while loop
  std::cout<<"0 is entered so you can't enter number anymore"<<std::endl;

  //selection sort algorithm
  for(int j{0};j<=N-2;j++)
    {
      int min{arr[j]};
      for(int k{j+1};k<N;k++)
	{
	  if(arr[k]<min)
	    {
	      min=arr[k];
	      arr[k]=arr[j];//exchanging
	      arr[j]=min;//placing the minimum member in the begining of the array
	    }
	}
    }
  
  //printing the sorted array
  for(int k{0};k<N;k++)
    {
      std::cout<<arr[k]<<std::endl;
    }

  
  return 0;
}
