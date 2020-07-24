#include <iostream>
using namespace std;
int main(){
    int input;
    int* array1 = (int*) malloc(sizeof(int));
    int* array2;
    int i{0};
    cout << "Type each number on seperate line then use 0 to sort it:" << endl;
    cin >> input;
    array1[0]=input;
    while(input!=0){
        cin >> input;
        i++;
        array2= (int*) malloc(sizeof(int)*i);
        for(int j{0}; j<=i; j++)
            array2[j]=array1[j];
        free(array1);
        array1=array2;
        array1[i]=input;
    }
        for(int j{0};j<=i;j++){
            for(int k{0};k<i;k++)
                if(array1[k]>array1[k+1])
                    swap(array1[k+1],array1[k]);
            
        }
	cout << "Result:";
        for(int k{1};k<=i;k++)
            cout << " " << array1[k];
    	cout << endl;
    
	return 0;
}
