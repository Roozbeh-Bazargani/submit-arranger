#include<iostream>
#include<vector>

int main(){

  std::vector<double> nums{};
  double tmp{};

  std::cout << "Please enter a number or enter 0 to close the array: ";
  std::cin >> tmp;
  if( tmp == 0 )
    return 0;

  else{
    while(tmp != 0 ){
      nums.push_back(tmp);
      std::cout << "Please enter a number or enter 0 to close the array: ";
      std::cin >> tmp;
    }
    for( int i{}; i<nums.size(); i++){
      for( int j{i}; j<nums.size(); j++){
	if( nums[j] <=  nums[i] ){
	  tmp = nums[i];
	  nums[i] = nums[j];
	  nums[j] = tmp;
	}
      }
    }

    for( int i{}; i<nums.size(); i++){
      std::cout << nums[i] << std::endl;
    }
    
  }

  return 0;
}
