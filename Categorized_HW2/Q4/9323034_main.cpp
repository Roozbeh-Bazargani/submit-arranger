#include "iostream"
#include "sstream"
#include "regex"
#include "string"

using namespace std;
using namespace regex_constants;

void selectionSort(vector<string> &numbers)
{
	int min_idx{};
	string holder;
	// One by one move boundary of unsorted subarray
	for (size_t i = 0; i < numbers.size() - 1; i++) {
		min_idx = i;
		for (size_t j = i + 1; j < numbers.size(); j++) {
			if (stoi(numbers[j]) < stoi(numbers[min_idx]))
				min_idx = j;
		}

		holder = numbers[min_idx];
		numbers[min_idx] = numbers[i];
		numbers[i] = holder;
	}
}

void printArray(vector<string> &numbers)
{
	size_t size = numbers.size();
	for (size_t i = 0; i < size; i++) {
		cout << numbers[i];
		if (i != size - 1)
			cout << ", ";
	}
}
// Driver program to test above functions
int main()
{

	string number{ "0" };
	string numbers{};
	do
	{
		cout << "Enter number or 0 for stop getting" << endl;
		getline(cin, number);
		regex e(R"(\d+)", ECMAScript | icase);
		if (regex_match(number, e))
		{
			numbers += number + " ";
		}
		else
			cerr << "number is not valid! Try again." << endl;

	} while (number != "0");

	
	stringstream stream(numbers);
	istream_iterator<string> begin(stream);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);

	selectionSort(vstrings);
	cout << "Sorted array:" << endl;
	printArray(vstrings);

	getchar();

	return 0;
}
