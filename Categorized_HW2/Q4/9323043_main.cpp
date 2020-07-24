#include<iostream>
#include<iomanip>

int* Set_size(int* a ,int M);

int main(){
  
  
  int Dummy;  //Dummy variable use for swaping
  int M{2};   //initial array size
  int* a{new int [M]};
  
  
  
  std::cout<<"Please Insert first  Number."<<std::endl;
 std::cin>>a[0];

 //sorting
  for (int i{1} ; a[i-1]!=0 ; i++)
    {
      if (i >= M) {  //array size must be increased
   a=Set_size(a , M);
   M=2*M;
    std::cout<<"Please Insert  next number then press Enter.(0 for end)"<<std::endl;
    std::cin>>a[i];
                   }
      else          //if i<=M no need to increase size ,just get number.
	{
	   std::cout<<"Please Insert next number then press Enter.(0 for end)"<<std::endl;
           std::cin>>a[i];
	}
             
 
    }
  
  for (int N{0} ; a[N]!=0 ;N++){
  for (int i{N+1} ; a[i]!=0 ; i++){

    if(a[N] > a[i]){
      //swaping a[N]  with smaller variable
      Dummy = a[N];  
      a[N] = a[i];
      a[i]=Dummy;
    }
     
    

  }
  }

  //Display sorted numbers

  std::cout<<"sorted Numbers are : "<<std::endl;
  for(int j{} ; a[j]!=0 ; j++){
    std::cout<<a[j]<<std::endl;
  }
 

  return 0;
}

int* Set_size(int* a , int M){

  int* a2{new int [2*M]};
  for (int i{} ; i<M ; i++)
    a2[i]=a[i];      //copy values from old array to new array
  //a2 = a;           //a and a2 points to a same address
  delete []a;
  
  return a2;
  
}
