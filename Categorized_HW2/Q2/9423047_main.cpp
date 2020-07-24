#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>




int main()

{
  std::string tmp;
  std::vector<std::string>store;
  std::vector<std::string>word;
  std::string spr{" .,()"};
  std::ifstream myfile("Error_find.txt",std:: fstream::in);

  size_t end{};
  int flag{};
  std:: string  ch{};
  int count{};

  if (myfile.is_open())
    {
      
      while (!myfile.eof())   //reading lines of the file
      {
	getline (myfile,tmp);
	store.push_back(tmp);
	
      }
    
    
      for(unsigned int i{}; i <store.size();i++)//extracting words from string 
      {
	 tmp=store[i];
	 size_t start{tmp.find_first_not_of(spr)};//taking start point from non                                                    //seperators
	
	while(start != std::string::npos)
	  {
	    end=tmp.find_first_of(spr,start+1);
	    if(end==std::string::npos)          //there is no seperator
	      {
		end = tmp.length();
	      }

	    word .push_back(tmp.substr(start, end - start)); //taking substring 
	    start = tmp.find_first_not_of(spr, end + 1);
	    
	  }
      }
    for(size_t j{};j<word.size();j++)
      {
	ch=word[j];                          //storing each word of array in ch
	for(size_t i{};i< ch.length(); i++)  //checking each character of word
	    {
	      switch (tolower(ch[i]))        //checing if the letter is vowel
	        {
                  case 'a': case 'e': case 'i': case 'o': case 'u':
                 	flag=1;
	          }
	
	      if(flag==0 && ch[i]==tolower(ch[i])) //not vowel and is lowercase
		 {
		 count++;
		 }
	      
                }
	 
	if(count>=5)  //checking if it is equal or greater than 5
	  {
	    	std::cout<<ch<<"  ";
      }
	 flag=0;
	 count=0; //changing count and flag to their first state for using them
	           // in next word
      }
    std::cout<<std::endl;
    myfile.close();
    }






  return 0;
}
