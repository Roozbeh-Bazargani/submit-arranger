#include <iostream>
#include <stack>


int main()
{
  double in{};
  std::stack<double> input;
  std::cout << "Enter numbers: ";
  std::cin >> in;
  while ( in ){ //get the numbers and push them in stack till 0 is entered
    input.push(in);
    std::cin >> in;
  }
  size_t count{input.size()}; //how many numbers have been entered
  size_t tempCount{count}; //save count
  double* const numbers{new double[count]}; // make room for the numbers
  while ( !input.empty() ){ //till the stack gets empty
    numbers[--tempCount] = input.top();//read from stack
    input.pop(); //and delete the number
  }
  double min{};
  size_t minPos{}; //position of minimum argument
  double temp{};
  for (size_t i{}; i < count - 1; i++){
    minPos = i;
    min = *(numbers+i);
    for(size_t j{i+1}; j < count; j++){ //see if there's any number lower after
      //the i'th position
      if (min > *(numbers+j)){ //if there is a lower number
	min = *(numbers+j); //change the saved minimum
	minPos = j; //and it's position
      }
    }
    //change the minimum number with i'th number
    temp = *(numbers+i);
    *(numbers+i) = *(numbers+minPos);
    *(numbers+minPos) = temp;
  }
  std::cout <<"Sorted array is:\n";//print the sorted list
  for(size_t i{}; i < count; i++)
    std::cout << *(numbers+i) << "  ";
  std::cout << std::endl;

  delete[] numbers;
  return 0;
}
