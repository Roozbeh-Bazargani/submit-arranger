#include<iostream>
#include<vector>

void sort(double*,size_t);  //  for sorting the vector by selection algorithm

int main()
{
  std::vector<double> vec;  //  for storing entries
  double temp;
  //  for getting values from user
  while(true){
    std::cin>>temp;
    if(temp==0)break;
    vec.push_back(temp);
  }
  sort(&vec[0],vec.size());
  //  for displaying sorted values
  for(size_t i{};i<vec.size();i++){
    std::cout<<vec[i]<<std::endl;
  }
}

void sort(double* p, size_t n){
  size_t min_index{};  //  to keep minimum value index
  double temp{};
  for(size_t i{1};i<n;i++){
    if (*(p+i)<*(p+min_index)) min_index=i;    
  }
  temp=*(p+min_index);
  *(p+min_index)=*p;
  *p=temp;
  if(n>1)sort(p+1,n-1);    //  recursive function
}
