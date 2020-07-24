#include<iostream>
#include<vector>

int main()
{
  std::vector<int> myVec; //vector of numbers
  size_t count{1}; //counter
  while(true)
    {
      int num{};
      std::cout<<"Enter Number "<<count<<" or press \"0\" to stop:"<<std::endl;
      std::cin>>num;
      if(num==0)
	break;
      myVec.push_back(num); //push back input number to vector
      count++;
    }


  for(size_t i{};i<myVec.size();i++)
    {
      int temp{};
      int min{myVec[i]}; //setting min to 1st element
      size_t min_idx{i}; //index of minimum
      for(size_t j{i+1};j<myVec.size();j++)
      {
	if(myVec[j]<min)
	  {
	    min=myVec[j];
	    min_idx=j;
	  }
      }
      temp=myVec[i];//swapping minimum and 1st element
      myVec[i]=myVec[min_idx];
      myVec[min_idx]=temp;
    
    }
  std::cout<<"\n=============Sorted Numbers============="<<std::endl;
  for(auto number:myVec)
    std::cout<<number<<std::endl;

}
