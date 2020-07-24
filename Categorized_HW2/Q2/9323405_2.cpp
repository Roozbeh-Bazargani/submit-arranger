#include <iostream>
#include <fstream>
#include <string>
using namespace std

int main () {
  string line;
   char test[5];
   int a=0;
   ifstream myfile ("/home/mana/Desktop/HW2" );
  if (myfile.is_open())
  {
  	myfile>>line;
  	while(myfile.eof()==0){
  	
  	a=line.size();
  	if(a<5){
  		myfile>>line;
  		continue;
  	}
  	for(int i=0;i<(a-4);i++){
  		int j=i,k=i;
  		int temp=0,temp1=0;
  		if(line[k]!=65&&line[k]!=69&&line[k]!=73&&line[k]!=79&&line[k]!=85&&65<=line[k]&&line[k]<=90)
  			temp1++;
  			k++;
  			if(line[k]!=65&&line[k]!=69&&line[k]!=73&&line[k]!=79&&line[k]!=85&&65<=line[k]&&line[k]<=90)
  			temp1++;
  			k++;
  			if(line[k]!=65&&line[k]!=69&&line[k]!=73&&line[k]!=79&&line[k]!=85&&65<=line[k]&&line[k]<=90)
  			temp1++;
  			k++;
  			if(line[k]!=65&&line[k]!=69&&line[k]!=73&&line[k]!=79&&line[k]!=85&&65<=line[k]&&line[k]<=90)
  			temp1++;
  			k++;
  			if(line[k]!=65&&line[k]!=69&&line[k]!=73&&line[k]!=79&&line[k]!=85&&65<=line[k]&&line[k]<=90)
  			temp1++;
  			k++;
  			if(temp1==5)
  			break;
  		
  			if(line[j]!=97&&line[j]!=101&&line[j]!=105&&line[j]!=111&&line[j]!=117)
  			temp++;
  			if(line[j]==65||line[j]==69||line[j]==73||line[j]==79||line[j]==85)
  			temp--;
    	j++;
    	
  			if(line[j]!=97&&line[j]!=101&&line[j]!=105&&line[j]!=111&&line[j]!=117)
  			temp++;
  		if(line[j]==65||line[j]==69||line[j]==73||line[j]==79||line[j]==85)
  			temp--;
  		j++;
    	
  			if(line[j]!=97&&line[j]!=101&&line[j]!=105&&line[j]!=111&&line[j]!=117)
  			temp++;
  		if(line[j]==65||line[j]==69||line[j]==73||line[j]==79||line[j]==85)
  			temp--;
  		j++;
    	
  			if(line[j]!=97&&line[j]!=101&&line[j]!=105&&line[j]!=111&&line[j]!=117)
  			temp++;
  		if(line[j]==65||line[j]==69||line[j]==73||line[j]==79||line[j]==85)
  			temp--;
  		j++;
    	
  			if(line[j]!=97&&line[j]!=101&&line[j]!=105&&line[j]!=111&&line[j]!=117)
  			temp++;
  		if(line[j]==65||line[j]==69||line[j]==73||line[j]==79||line[j]==85)
  			temp--;
  		if(temp==5){
  			cout<<line<<'\n';
  			break;
  		}
  	  }
  	 myfile>>line;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
