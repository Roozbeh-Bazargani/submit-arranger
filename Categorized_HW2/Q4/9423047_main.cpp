#include<iostream>
#include<string>
#include<vector>


int main()
{
  int tmp{};
  int num{};
  std::vector<int>v;

  std::cout<<"please enter numbers and if you are  done end this process by entering 0";

  std::cin>>num;
  v.push_back(num);
  
  while(num != 0)
    {
      std::cin>>num;
      v.push_back(num);
    }
  tmp=v[0];
  for(size_t i{};i<(v.size()-1);i++)
    {
      for(size_t j=i+1;j<(v.size()-1);j++)
	{
	  if(v[i]>v[j])
	  {
	    tmp=v[i];
	    v[i]=v[j];
	    v[j]=tmp;
	  }
	  
	}
    }
  
   for(size_t i{};i<(v.size()-1);i++)
   std::cout<<v[i]<<std::endl;
  // std::cout<<tmp<<std::endl;
  return 0;
}
