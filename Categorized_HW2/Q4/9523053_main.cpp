#include <iostream>
#include <vector>

int main ()
{
  std::cout<<std::endl<<std::endl;
  std::cout<<"----------------------------"<<std::endl;
  std::cout<<"-----------9523053----------"<<std::endl;
  std::cout<<"----------------------------"<<std::endl;
  std::cout<<std::endl<<std::endl;

  std::vector<int> myvector;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):"<<std::endl;
  /*
  create the vector (array)
  */
  do
  {
    std::cin >> myint;
    myvector.push_back (myint);
  } while (myint);


  int temp ;
  long unsigned int n{myvector.size()};
  unsigned int pos_min ;

	for (unsigned int i{} ; i < n-1 ; i++)
	{
    //set pos_min to the current index of array
	  pos_min = i;

		for (unsigned int j{i+1} ; j < n ; j++)
		{

		    if (myvector[j] < myvector[pos_min])
        {
          /*
          pos_min will keep track of
          the index that min is in, this is needed when a swap happens
          */
          pos_min=j;
        }
	  }

	   /*
    if pos_min no longer equals i than a
    smaller value must have been found, so a swap must occur
    */
    if (pos_min != i)
    {
         temp = myvector[i];
         myvector[i] = myvector[pos_min];
         myvector[pos_min] = temp;
    }
	}
  /*showing the result*/
  std::cout<<std::endl<<std::endl;
  std::cout << "array stores " << int(myvector.size())<< " numbers.";
  std::cout<<std::endl<<"sorted array:"<<std::endl<<std::endl;
  for(unsigned int i{} ; i < myvector.size() ; i++)
  {
    std::cout<< myvector[i]<< "  ";
  }
  std::cout<< std::endl;
  return 0;
}
