#include"english.h"
// a boolean function to determine type of the letter.
bool isConsonant(char input){
	char ConsonantChar[21] ={'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
	for(int i{0}; i<21;i++){
		if(input == ConsonantChar[i]){
			return true;	
		}
	}
	return false;
}
// a boolean function to determine the letter shape.
bool isUpperCase(char input){
	if(input>64 && input<91)
		return true;
	return false;
}
