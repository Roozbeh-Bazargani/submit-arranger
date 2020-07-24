#include<iostream>
#include<vector>


int main()
{
  double x{1};   
  std::vector<double> num;
  
  std::cout << "please enter your numbers until 0 : " <<std::endl;

  while(true)   //getting number from user
    {
      std::cin >> x;
      if(x!=0)
	{
	  num.push_back(x);
	}
      else
	{
	 
	  break;
	}
    }
  
  for(size_t i{}; i <num.size() ; i++)
    {      
      double temp{};
      double small{num[i]};
      size_t index_small{i};
      
      for(size_t j{i+1} ; j < num.size() ; j++)
	{
	  if(num[j] < small)
	    {
	      small = num[j];
	      index_small = j;
	    }
	 
	}
     
      if(index_small != i)  
	{
	  temp = num[i];
	  num[i] = small;
	  num[index_small] = temp;
	}
    }

  std::cout << "Your numbers are sorted!" << std::endl;
  for(size_t i{}; i <num.size() ; i++)
    {
       std::cout << num[i] << " " ;
    }
  
  std::cout << std::endl;
  
  return 0;
}
