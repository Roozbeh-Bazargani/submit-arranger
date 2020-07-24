#include<iostream>
#include<string>
//selectionSort function definition
void selectionSort(double* , int );

int main(){
  int counter{1};
  int dynamicLength{1};
  double Pvalue{};
  //dynamic array with length one for saving the input value
  double* getNum = {new double[dynamicLength]};
  double* array{};
  
  
  //getting the fisrt number of array from user
  std::cout << "please enter a number: "<< std::endl;
  std:: cin >> Pvalue;
  std::cout << std::endl;
  getNum[counter - 1] = Pvalue;
   
  
  
  
  while(Pvalue != 0){
    counter++;
    /*checking if the lenght of dynamic array is lower than the number of input
      that user will enter*/ 
    if( dynamicLength < counter ){
      //definig temparary array to copy the value of last array
      array = {new double[counter]};
      
      for(int j{}; j < dynamicLength; j++){
	array[j] = getNum[j];
        
	  }
      delete[]getNum;
      dynamicLength = counter;
      //defining new dynamic array with expand length
      getNum = {new double[dynamicLength]};
      //copying from temporary array to main array
      for(int k{}; k < dynamicLength - 1; k++){
	getNum[k] = array[k];
      }
      delete[]array;
      
    }
      
    
    //asking for the new number
    std::cout << "please enter a number: "<< std::endl;
    std:: cin >> Pvalue;
    std::cout << std::endl;
    getNum[dynamicLength - 1] = Pvalue;
    
    
  }
  
  if(Pvalue == 0){
    //showing the array which the user is entered
    std::cout << "The array you entered is: "<< std::endl;
     for(int i{}; i < counter; i++){
       std::cout << getNum[i] << '\t';
     }
    std::cout<< std::endl;
    std::cout << "you enter 0, now we show the selection sort"
	      << " of the numbers you had entered: "<< std::endl;
    
    
  }
  //calling the selection sort function
  selectionSort( getNum, counter);
  
  return 0;
  
}
//declaring the selection sort function
void selectionSort(double* listofNumber, int counter){
  int minPosition{};
  double temp;
  for( int i{}; i < counter-1 ; i++){
    //assigning the first unit of array as min
    minPosition = i;
    for(int j{i+1} ; j < counter; j++){
      //checking of that unit is really the min one
      if( listofNumber[j] < listofNumber[minPosition]){
	minPosition = j;
      }
      //swaping with the new min
	if(minPosition != i){
	  temp = listofNumber[i];
	  listofNumber[i] = listofNumber[minPosition];
	  listofNumber[minPosition]= temp;
	}
      
      
    }
  }
  for(int k{}; k < counter; k++){
    std::cout<< listofNumber[k] << '\t';
  }
  std::cout<<std::endl;
}

