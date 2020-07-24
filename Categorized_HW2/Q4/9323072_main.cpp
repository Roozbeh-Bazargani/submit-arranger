#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>


void selectionsort(int , double*);
int main(){
  
  std::string str{};
  int end{};
  int start{};
  double number{};
  std::string sNumber{};
  int sNum{};

  int count{};
  double* p{};
  bool flag{true};
  double num{};
  // read the number form user and store them in the string and put # between them fr identifing 
  std::cout << "pleas enter your numbers" << std::endl;
  for (int i{}; flag; i++){
     std::cin >> num;
    if(num == 0)
      flag = false;
    else{
      count++;
      str += std::to_string(num);
      str += "#";
      
    }
  }
  //find the number from string by # sign  and store them in array
  p = {new double[count]};
  for(size_t j{}; j < str.length(); j++){
    if(str[j] == '#'){
      end = j;
      sNumber = str.substr(start,end-start);
      number = std::stod(sNumber);
      p[sNum] = number;
      sNum++;
      start = end + 1;
    }
    
  }
  std::cout << "the numbers are : " << std::endl;
   for(int k{}; k < sNum; k++){
    std::cout << p[k] <<'\t';
  }
   std::cout << std::endl;
  selectionsort(sNum, p);
 
return 0;
}

/* the selection sort method by 2 for and finding min value in each iteration*/
 void selectionsort (int length , double*p){
  int mini{};
  double temp{};
  
  for(int j{}; j  < length-1; j++){
  mini = j;
  for(int i{j+1}; i < length; i++){
    if(p[i] < p[mini]){
      mini = i;
    }
  }
  if(mini != j){
  temp = p[j];
  p[j] = p[mini];
  p[mini] = temp;
  }
  

  
  }
   std::cout << "the numbers are sort now : " << std::endl;
   for(int k{}; k < length; k++){
    std::cout << p[k] <<'\t';
  }
   std::cout << std::endl;

}
