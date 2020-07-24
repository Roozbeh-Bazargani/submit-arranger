#include<iostream>
#include<string>
#include<fstream>
#include<locale>

bool is_wrong( std::string&, int, int);

int main(int argc, char* argv[]){

  std::string file_path{"Error_find.txt"};
  std::ifstream file_obj( file_path );
  std::string line_string{};

  int line_num{};
  int word_char_count{};
  int words_num{};
  int p{};
  int errors_num{};
  
  std::cout << "Errors: ";
  
  if( file_obj.is_open()){
    while( std::getline(file_obj, line_string)){
      line_num++;
      
      for( size_t i{}; i<line_string.length(); i++){
	if((line_string[i] == ' ') || (!std::isalpha(line_string[i]))){
	  if(word_char_count > 0){
	    words_num++;
	    if(is_wrong(line_string, i, word_char_count)){
	      std::cout << std::endl;
	      std::cout << "word number " << words_num << " is wrong: ";
	      for(int j{}; j <  word_char_count; j++){
		p = i -  word_char_count + j;
		std::cout << line_string[p];
		  
	      }
	     
	      
	      errors_num++;
	    }
	  
	  }
	  
	  word_char_count = 0;
	}
	else if(i == (line_string.length()-1) ){
	  words_num++;
	  word_char_count = 0;
	  if(is_wrong(line_string, i, word_char_count)){
	    std::cout << std::endl;
	    std::cout << "word number " << words_num << " is wrong"  << std::endl;
	    for(int j{}; j <  word_char_count; j++){
	      p = i -  word_char_count + j;
	      std::cout << line_string[p];

	    }
	    errors_num++;
	      
	  }
	}
	
	else{
	  word_char_count++;
	}
	
      }
    }
  }
  if( errors_num == 0 ){
    std::cout << "\b\b\b\b\b\b\b\bNo Error!";
  }
  std::cout << std::endl;
  std::cout << "Document containts " << words_num << " Words"  << std::endl;
  
  return 0;

}

bool is_wrong( std::string& line_pointer, int loc, int size){
  int con_count{};
  bool pre{false};
  int uppers{};
  int j{};
  for( int i{}; i < size; i++){
    j = loc - size + i;
    
    switch( std::tolower(line_pointer[j]) )
      {
    	case 'a': case 'i': case 'o': case 'e': case 'u':
    	  pre = false;
    	  break;
    	default:
	  
    	  if( i==0 ){
    	    con_count++;
    	  }
    	  else if(pre){
    	    con_count++;
    	  }
    	  else{
    	    con_count = 1;
    	  }
    	  pre = true;

	  if(std::isupper(line_pointer[j]))
	    uppers++;
    	  break;
      }
  }
    if(con_count >= 5 && uppers != size){
      return true;
    }
    else{
      return false;
    }
}
