//Created By Mohammad Sadegh Safari 9323046

#include<iostream>
#include<vector>

//Declaring functions
void sort(std::vector<double>& a, size_t N);

int main()
{
  std::vector<double> Nums;
  double Num{1};
  std::cout << "plz enter nums and press enter after inserting everyone" << std::endl;

  //input numbers until user enter 0 and storing them in a vector
  while( Num != 0) {
    std::cin >> Num;
    
    if(Num != 0) {
      Nums.push_back(Num);
    }
    else
      break;
  }

  //sorting numbers using sort function
  sort(Nums, Nums.size());
  std::cout << "sorted nums are:" << std::endl;

  //print sorted numbers
  for(size_t i{}; i < Nums.size(); i++) {
    std::cout << Nums[i] << std::endl;
  }

  return 0;
}


void sort(std::vector<double>& a, size_t N) {
  double temp{};
  size_t index{};

  //implement selction sort algorithm
  for(size_t i{}; i < N-1; i++) {
    index = i;
    
    for(size_t j{i+1}; j < N; j++) {
      
      if(a[index] < a[j]) {
	index = j;
      }
      
    }
    
    if(index!=i) {
      temp = a[i];
      a[i] = a[index];
      a[index] = temp;
    }
    
  }
  
}
