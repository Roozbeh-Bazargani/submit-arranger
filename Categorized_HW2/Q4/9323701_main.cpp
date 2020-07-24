//By Navid Hasanzadeh 9323701
#include<iostream>
#include<vector>

void sort(std::vector<double> &v, unsigned int startIndex);
int main(){
	// Vector is used, because the input size is unkown.
	std::vector<double> v;
	double input{-1};
	// Read the user inputs while 0 is not entered and save them in a vector.
	while (true){
		std::cin >> input;
		if (input==0)
			break;
	// push the input to the vector		
		v.push_back(input);
	}
	// call sort function
	if(v.size()>0)
		sort(v, 0);
	// print the sorted list.
	for(double num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
	return 0;
}
// sort function with a vector refrence and start index as it's inputs.
void sort(std::vector<double>& v, unsigned int startIndex){
	double minValueIndex = startIndex;
	// find the minimum value between startIndex and end of the vector.
	for(unsigned int i{startIndex}; i < v.size(); i++){
		if (v[minValueIndex] > v[i]){
			minValueIndex = i;
			}	
	}		
	// swap the vector elements
		std::swap(v[startIndex], v[minValueIndex]);
	// the function calls itself until all vector elements be check. 
	if(startIndex < v.size()-1)
			sort(v, startIndex + 1);
}
