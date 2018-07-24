/*
Idex: p.131
Title: Binary search
Description: Given array A, find the index of x
Time Complexity: O(logN)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& A, int x) {
	int lo = -1, hi = A.size();
	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (A[mid] < x)
			lo = mid;
		else
			hi = mid;
	}
	return hi;
}

int main() {
	vector<int> A{ 32,41,5,3,23,513,63,2,35, 8 };
	sort(A.begin(), A.end(), [] (int first, int second)-> bool
	{
		return first < second;
	});
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << " ";
	}
	cout << endl;
	int x = 63;
	cout << "In array A, the 'x' is located at " << binarySearch(A, x) << endl;
	return 0;
}
