#include<iostream>
#include<vector>
int min(std::vector<int>& vec); //returns the index of minimum element
int main()
{
std::vector<int> numbers;
int num{};
std::cout << "Please Enter Numbers That You Want to Be Sorted" << std::endl;
std::cout << "separate them with space or enter" <<std::endl;
std::cout <<"and when it's done enter 0 and Press enter" << std::endl;
do
{
std::cin >> num;
numbers.push_back(num);
}while(num); //gets numbers until you enter 0 
numbers.pop_back(); //deletes the 0 at the end

size_t firstSize{numbers.size()}; //stores the size of vector that is enteres by user
std::vector<int> finalvector; //the vector with sorted elements
for(size_t i{}; i < firstSize; i++)
{
	finalvector.push_back(numbers[min(numbers)]); //saves the minimum element in new vector
	numbers.erase(numbers.begin() + min(numbers)); //erases the minimun of old vector
}
for(size_t i{}; i < finalvector.size(); i++)
{
	std::cout << finalvector[i] << "  " ; //shows the sorted vector
}
return 0;
}

int min(std::vector<int>& vect)
{
int indexofMin{};
int temp{vect[0]};
for(size_t i{}; i < vect.size(); i++)
{
	if(vect[i] < temp)
	{
	   temp = vect[i];
	   indexofMin = i;
	}
}
return indexofMin;
}
