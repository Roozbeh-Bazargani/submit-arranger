#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

bool IsCorrect(std::string&);

int main(){
  std::ofstream ofile{"Error.txt", std::ios::app};
  std::ifstream ifile{"Error_find.txt"};
  std::string str;
  while(!ifile.eof()){
    ifile >> str;
    if(!IsCorrect(str))
      ofile << str << " ";
    //    std::cout << str << " ";
  }
  ifile.close();
  ofile.close();
  return 0;
}

bool IsCorrect(std::string& StrW){
  size_t N{StrW.length()};
  size_t flag{0};
  //std::cout << "," << N << ",";
  char VowelArr[]{'a','e','i','o','u'};
  char signChar[]{'(',')','\'',',','.','\"','>','<'};
  if(N>=5){
    for(size_t i{0}; i<N; i++)
      for(size_t j{0}; j<5; j++)
	if(StrW[i]==VowelArr[j])
	  flag = 1;
    if(flag==1){
      return true;
    }
    else{
      for(size_t j{0}; j<8; j++){
	if(StrW[0]==signChar[j])
	  StrW.erase(0,1);
       	if(StrW[N-1]==signChar[j])
	  StrW.erase(N-1);
      }
      N = StrW.length();
      for(size_t i{0}; i<(N); i++)
	if(StrW[i]>='A' && StrW[i]<='Z')
	  return true;
      return false;
    }
  }
  else{
    return true;
  }
}
