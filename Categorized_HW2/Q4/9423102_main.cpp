#include<iostream>
#include<vector>
int main(){
  double input{1};
  double intermediate{};
  double min{};
  std::vector<double> arr;
  size_t pos{};

  
  std::cout << "enter the inputs :" << std::endl;
  while(input != 0){
    std::cin >> input;
    arr.push_back(input);
  }
  std::cout << "******************** input numbers ********************" << std::endl;
  for(size_t i{}; i<arr.size(); i++)
    std::cout << arr[i] << "   ";
  std::cout << "\n";
  
  //**************** this part is for sorting the entered numbers ******************
  for(size_t i{}; i<arr.size()-1; i++){
    min = arr[i];
    pos = i;
    for(size_t j{i+1}; j<arr.size(); j++){
      if(min > arr[j]){
	min = arr[j];
	pos = j;
      }
    }
    intermediate = arr[pos];
    arr[pos] = arr[i];
    arr[i] = intermediate;
    }
  //********************************************************************************
  
  std::cout << "******************** sorted numbers *******************" << std::endl;
  for(size_t i{}; i<arr.size(); i++)
    std::cout << arr[i] << "   ";
  std::cout << "\n";
  
  return 0;
}
