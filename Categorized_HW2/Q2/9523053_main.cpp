#include <iostream>
#include <fstream>
#include <string>
/*
check_f function checks out the char which are not capital
and !=a,e,o,i,u
*/
bool check_f (char);


int main (){
  std::string item_name;
  int first_num{} ;

  std::cout<<std::endl<<std::endl;
  std::cout<<"----------------------------"<<std::endl;
  std::cout<<"-----------9523053----------"<<std::endl;
  std::cout<<"----------------------------"<<std::endl;
  std::cout<<std::endl<<std::endl<<"Wrong words:";
  std::cout<<std::endl<<std::endl;

  /*opening the file */
  std::ifstream nameFileout;
  nameFileout.open("Error_find.txt");
  std::string line;
  while(std::getline(nameFileout, line))
  {
      for(unsigned int i{} ; i<line.length() ; i++ )
      {
        /*
        check chars one by one
        */
        if ( check_f(line[i]) )
        {
          std::cout<< line[i];
          first_num++ ;
        }
        /*
        get ready for chech next word.
        */
        if( ( (line[i] == ' ') || (line[i] == '.') ) && (first_num >= 5) )
        {
          first_num=0;
          std::cout<<std::endl;
        }
        /*
        deleting extra chars.
        */
        if ( (!check_f(line[i]) ) && (first_num<5) )
        {
          for (int j{} ; j<first_num ;j++)
            {
              std::cout<<'\b';
            }
            first_num=0;
        }

      }
  }
  nameFileout.close();
  std::cout<<std::endl;
  return 0;
}

/*
check_f function checks out the char which are not capital
and !=a,e,o,i,u
*/
bool check_f (char c)
{
  if( ( ('a'<c) && ('e'>c) ) || ( ('e'<c) && ('i'>c) ) || ( ('i'<c) && \
   ('o'>c) ) || ( ('o'<c) && ('u'>c) ) || ( ('u'<c) && ('z'>=c) ) )
  {
    return true;
  }
  else
    return false;
}
