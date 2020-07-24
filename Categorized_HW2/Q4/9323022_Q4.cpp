#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  int n{0};
  int input{1};
  int* input_buffer{new int[n]};
  int* input_array{new int[n]};
   
  while(input != 0)
    {
      cin >> input;
      n++;
      if (input != 0);
      {
	for(int i=0; i<(n-1); i++)
	  input_buffer[i] = input_array[i]; //copy input_array to input_buffer
	input_array = new int[n]; //when you change size of the array, all datas will be cleared.
	for(int i=0; i<(n-1); i++)
	  input_array[i] = input_buffer[i];
	input_array[n-1] = input;
	input_buffer = new int[n]; //make bigger buffer
      }
    }
  n--; //last number was 0 and we don't like it!!

  for (int i{0}; i<(n-1); i++) //selection sort
    for (int j{i}; j<n; j++)
      if (input_array[j] < input_array[i])
	{
	  int plate{input_array[i]}; //swip
	  input_array[i] = input_array[j];
	  input_array[j] = plate;
	}

  cout << "\nselection sort resualt:\n";
  for (int i{0}; i<n; i++)  //print sorted input_array
    cout << input_array[i] << endl;

  return 0;
}
