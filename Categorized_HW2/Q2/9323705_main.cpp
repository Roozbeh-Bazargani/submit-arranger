#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using std::string;

int main()
{
string text;


string f;
string file{"Error_find.txt"};
std::ifstream pf {file};
if(!pf)
{std::cout<<"File can not open!!"<<std::endl;
return 1;}


while(pf>>f)
{
text=(text+" "+f);
}
std::cout<<"the file is:"<<text<<std::endl;

const string separators{ " (),;:.\"!?'\n-" };
std::vector<string> words;
string word;
 int v,s,e,m;
const string vowels_and_Caps{"AEIOUaeiouQWRTYPSDFGHJKLZXCVBNM"};


for (size_t i{};i<text.length();)
{
    if (text.find_first_not_of((vowels_and_Caps+separators),i)!=string::npos)
           {

            v++;
            if ((text[i]=='a'||text[i]=='A'||text[i]=='e'||text[i]=='E'||text[i]=='i'||text[i]=='I'||text[i]=='o'||text[i]=='u'||text[i]=='O'||text[i]=='U'||text[i]==' '))
                {
                v=0;
                //std::cout<<"vowel or space has detected!!"<<std::endl;
                } 
            i=text.find_first_not_of((vowels_and_Caps+separators),i)+1;
            //std::cout<<"new v= "<<v<<" of char= "<<text[i-1]<<std::endl;
                       
            if (v>=4)
                {m++;
                 v=0;
                e=text.find_first_of(separators,i);
                s=text.rfind(" ",e-1)+1;
                word=(text.substr(s, e - s));                
                i=e;
                std::cout<<"the mistake was "<<word<<std::endl;
                }
           }
    else
        break;

}
}


