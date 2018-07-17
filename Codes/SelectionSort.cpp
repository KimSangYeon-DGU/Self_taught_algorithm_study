/*
Idex: p.111
Title: Selection sort
Description: Given array, sort the array using selection sort
Time Complexity: O(N^2)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int getRandValue(int max) {
	return rand() % max + 1;
}

void selectionSort(vector<int>& A) {
	for (int i = 0; i < A.size(); ++i) {
		int minIndex = i;
		for (int j = i + 1; j < A.size(); ++j) 
			if (A[minIndex] > A[j])
				minIndex = j;
		std::swap(A[i], A[minIndex]);
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int N;
	N = 27;
	vector<int> array;
	for (int i = 0; i < N; ++i) {
		array.push_back(getRandValue(100));
	}

	cout << "Before sorting: ";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	selectionSort(array);
	cout << "After sorting: ";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}