#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
bool  vowel_check(char*, int i);

int main()
{
  int N{};
  std::ifstream file{"Error_find.txt"};
  char data;
  char * arr{new char [N]};
  while (! file .eof()) {
    data=file.get();
    arr[N] = data;
    N++;
    }
  
   for (int i{}; i<N; i++)
    {
      if (arr[i] == ' ')
	{i++;
	  int k{};
	  while(vowel_check(arr, i))
	    { i++;
	      k++;}
	  if (k>=5){
       
	  for (int j{i-k};j<i;j++)
	    cout<<arr[j];
	  cout<<endl;
	    }

	  k=0; 
	}

	}

  
  return 0; 
}

bool vowel_check(char *a , int i )
  
{
    return ((a[i] != 'a') && (a[i] != 'e') && (a[i] != 'i') && (a[i] !='u') &&
	    (a[i] != 'o') && (a[i] != ' ') && ! isupper(a[i]) );
}

