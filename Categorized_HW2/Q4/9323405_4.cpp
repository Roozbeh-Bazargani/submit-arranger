#include <iostream>

using namespace std;



void selectSort(int arr[], int n)
{
//pos_min is short for position of min
    int pos_min,temp;

    for (int i=0; i < n-1; i++)
    {
        pos_min = i;

        for (int j=i+1; j < n; j++)
        {

            if (arr[j] < arr[pos_min])
                pos_min=j;
            
        }

        
        if (pos_min != i)
        {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
    for (int k = 0; k < n ;k ++) {
        cout«arr[k];
    }

}


int main{
        for(int l = 0 ; l < n){
            int arr[1000];
            int n = 0;
        }
        



        Public entry() {
std::cout << "enter your number" << std::endl;
int temp;
std::cin >> temp;

            if (temp == 0) {
                return selectsort(arr, n);
            } 
            else {
               
                std::cin >> arr[n] >> temp;
                n++;
                entry()
            }
        }
        };
