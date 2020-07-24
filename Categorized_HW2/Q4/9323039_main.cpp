#include<iostream>
#include<cmath>


int min( int *,int ,int ,int&  ...);
 
int main()
{

  int N{};
  int k{};
  int *arr{new int [N]};

  std::cin>>arr[N];

   while (arr[N] != 0){
      N++;
  std::cin>>arr[N];
  
 }
   std::cout<<"array entered"<<std::endl;

   for (int i{}; i<N-1 ; i++)
     {
     
       int x{arr[i]};
       arr[i] = min(arr,N, i, k);
       arr[k] = x;
     }
      for (int i{}; i<N ; i++)
     {
       std::cout<<arr[i]<<std::endl;
     }
   

  return 0;
}
int min(int *arr,int N,int i, int& k,...){
  int s{arr[i]};
  for (int j{i+1};j<N;j++ )
    if(arr[j]<s)
      { s=arr[j];
	k=j;}
  return s;
}
 
	   
