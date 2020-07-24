#include<iostream>

int main()
{
  int n{};
  int i{};
  int* A{new int [n]}; //definition of the dynamic array.
  double a{1};
  
  
  
  while(a!=0)   // the loop for get data from user & store in dynamic array.
    {
 
     std::cout<<"please enter a number"<<std::endl;
     std::cin>>a;
     A[i]=a;
     i++;
     n++;
       
    }
  
  for(int c{};c<n-1;c++)   //the loop for selection sort the data
    {
      for(int k=c+1;k<n;k++)
	{
	  if(A[c]>A[k])
	    {
	      int temporary{}; 
	      temporary=A[c];
	      A[c]=A[k];
	      A[k]=temporary;

	    }
	}

  
      
    }
 
  for(int c{1};c<n;c++)   //the loop for display the members of array as the final result.
 std::cout<<A[c]<<" " ;
 std::cout<<std::endl;
 return 0;

}
