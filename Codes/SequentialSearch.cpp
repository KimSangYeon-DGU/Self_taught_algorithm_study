/*
Idex: p.108
Title: Find element in array
Description: Given array, let's find element in array, then return its index
Time Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int getRandValue() {
	return rand() % 30 + 1;
}
int sequentialSearch(vector<int>& array, int element) {
	for (int i = 0; i < array.size(); ++i) {
		if (array[i] == element)
			return i;
	}
	return -1;
}

int main() {
	srand((unsigned int)time(NULL));

	int n = 20;
	vector<int> array;
	for (int i = 0; i < n; ++i) {
		array.push_back(getRandValue());
	}

	for (int i = 0; i < 20; i++) {
		cout << array.at(i) << " ";
	}
	cout << endl;

	int element = getRandValue();
	cout << "In array, index of element " << element <<  " to find: " ;
	cout << sequentialSearch(array, element) << endl;

	return 0;
}

