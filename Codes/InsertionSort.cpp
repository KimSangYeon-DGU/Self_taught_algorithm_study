/*
Idex: p.112
Title: Insertion sort
Description: Given array, sort the array using insertion sort
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

void insertionSort(vector<int>& A) {
	for (int i = 1; i < A.size(); ++i) {
		int j = i;
		while (j > 0 && A[j - 1] > A[j]) {
			std::swap(A[j - 1], A[j]);
			--j;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	int N;
	N = 32;
	vector<int> array;
	for (int i = 0; i < N; ++i) {
		array.push_back(getRandValue(100));
	}


	cout << "Before sorting: ";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;

	insertionSort(array);
	cout << "After sorting: ";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}