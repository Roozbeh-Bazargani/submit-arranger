#include<iostream>
#include<vector>


int main()
{
  std::vector<double> numbers{};
  double number{};
  std::cout << "Please enter your numbers,when you're done enter 0:" << std::endl; //getting number
  do{
    std::cin >> number;
    numbers.push_back(number); 
  }
  while(number != 0.0);
  numbers.pop_back(); //Deleting last element(zero)

  std::cout << "unsorted numbers :" << std::endl; //Displaying unsorted numbers
  for(size_t i{}; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;
  
  for(size_t i{}; i < numbers.size(); i++){
    size_t iMin{i};
    for(size_t j{i+1}; j < numbers.size(); j++){
      if(numbers[iMin] > numbers[j])
	iMin = j;
    }
    if(iMin != i){
      double temp{numbers[iMin]};
      numbers[iMin] = numbers[i];
      numbers[i] = temp;
    }
  }

  std::cout << "sorted numbers :" << std::endl; //Displaying sorted numbers
  for(size_t i{}; i < numbers.size(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;
  
  return 0;
}
