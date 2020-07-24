#include "Queue.h"
using namespace std;
Queue::Queue(string myfilename){
	ifstream myfile;
	myfile.open(myfilename);
	string len_str;
	getline(myfile,len_str );
	len=stoi(len_str); //define len as int in header
	pointer=(float*) malloc(sizeof(float)*len); //define float* pointer in header
	string values;
	getline(myfile, values);
	if(values[values.length()-2]!=',')
		values+=",";
	string value1="";
	location=0;	//define location as int in header
	for(unsigned int i{0}; i <= values.length() ; i++)
		if(values[i]!= ',')
			value1+= values[i];
		else{
			pointer[location]=stof(value1);
			location++;
			value1="";
		}
	myfile.close();
}
Queue::~Queue(){
	location=0;
	len=0;
	free(pointer);
}

void Queue::displayQueue(){
	for(int i{0};i<len;i++)
		cout << pointer[i] << " ";
	cout << endl;
}

void Queue::enQueue(float num){
	if(location < len){
		pointer[location]=num;
		location++;
	}
	else
		cout << "Full" << endl;

}

float Queue::deQueue(){
	if(location){
		float temp=pointer[0];
		for(int i{0};i<len;i++){
			pointer[i]=pointer[i+1];
		}
		pointer[len-1]=0;
		return temp;
	}
	else{
		cout << "Empty" << endl;
		return false;
	}

}
