#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void check(string mystring){
  unsigned int num_space_perv{0};
  unsigned int num_space_next{0};
  for(unsigned int i{0};i<mystring.length();i++){
    if(mystring[i] == ' ' || mystring[i] == '.' || mystring[i] == '-' ){
      num_space_perv=num_space_next;
      num_space_next=i;
      if(num_space_next - num_space_perv > 5)
        if(mystring.find_first_of("abcdefghijklmnopqrstuvwxyz" , num_space_perv) < num_space_next){
          unsigned int num_vow_next=num_space_perv + 1;
          unsigned int num_vow_perv=num_vow_next;
          for(unsigned int j=num_space_perv; j<num_space_next;j++)
            if(mystring[j]=='a' || mystring[j]=='i' || mystring[j]=='e' || mystring[j]=='o' || mystring[j]=='u'  || j+1==num_space_next){
	      num_vow_perv=num_vow_next;
              num_vow_next=j;
              if(num_vow_next - num_vow_perv > 6 || (num_space_perv+1==num_vow_perv && j==num_space_next -1)){
               for(unsigned int k=num_space_perv+1; k<num_space_next; k++)
		cout << mystring[k];
	       cout << " ";
              }
             }
        } 
    }
  }

}
int main(){
  string mystring;
  ifstream myfile;
  myfile.open("Error_find.txt");
  while(getline(myfile,mystring))
    check(mystring);
  myfile.close();
  cout << endl;
  return 0;
}
