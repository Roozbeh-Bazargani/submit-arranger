#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>

double* indexMinArr(double*, double*);
void swapArr(double* , double*);

int main(){
  double Num;
  std::string strNum{};
  double* iMin;
  double* buff;
  size_t len{0}, i{}, j{};
  std::ostringstream oss{};
  while(std::cin >> Num){
    //len = 0;
    if(Num == 0)
      break;
    oss << Num << '\t';
    //std::string strNum{}
    //strNum = strNum + Num + '\t';
    strNum = oss.str();
    //std::cout << strNum;
    len++;
  }
  std::istringstream iss{strNum};
  double* p{new double[len]};
  for(i=0; i<len; i++)
    iss >> *(p+i);
  //for(i=0; i<len; i++)
  //  std::cout << *(p+i);
  for(i=0; i<len; i++){
    buff = (p+i);
    for(j=i+1; j<len; j++){
      iMin = indexMinArr(p+i,p+j);
      if(*iMin<=*buff)
	buff=iMin;
    }
    swapArr(p+i,buff);
  }
  for(i=0; i<len; i++)
    std::cout << *(p+i) << ',';
  std::cout << std::endl;
  delete[] p;
  return 0;
}

double* indexMinArr(double* p1, double* p2){
  if(*(p1)<=*(p2))
    return p1;
  return p2;
}

void swapArr(double* p1, double* p2){
  double p3 = *p1;
  *p1 = *p2;
  *p2 = p3;
}
