/*
Idex: p.118
Title: Max sum
Description: Given array A, calculate maximum sum of sub-array in array A
Time Complexity: O(NlogN)
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

const int MIN = numeric_limits<int>::min();

int getRandValue(int max) {
	int sign = rand() % 2;
	int rand_val = rand() % max + 1;
	if (!sign)
		rand_val *= -1;
	return rand_val;
}

int maxSum(const vector<int>& A, int lo, int hi) {
	if (lo == hi) return A[lo];
	int mid = (lo + hi) / 2;
	int left = MIN, right = MIN, sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += A[i];
 		left = max(left, sum);
    }
	sum = 0;
	for (int j = mid + 1; j <= hi; ++j) {
		sum += A[j];
		right = max(right, sum);
	}

	int single = max(maxSum(A, lo, mid), maxSum(A, mid+1, hi));

	return max(left + right, single);
}

int main() {
	srand((unsigned int)time(NULL));
	int N = 20;
	
	vector<int> A;
	
	for (int i = 0; i < N; ++i) {
		A.push_back(getRandValue(100));
	}

	for (int i = 0; i < N; ++i) {
		cout << A.at(i) << " ";
	}
	cout << endl;

	cout << "Max sum: " << maxSum(A, 0, N-1) << endl;
	return 0;
}