#include <iostream>
#include <vector>
#include "func.h"

int main()
{
	std::vector<double> Nums,N;
	Nums = getNums();
	show_Nums(Nums);
	sort(Nums);
	std::cout << "sorted numbers are : " << std::endl;
	show_Nums(Nums);



	return 0;
}

