/*
Idex: p.118
Title: Max sum
Description: Given array A, calculate maximum sum of sub-array in array A
Time Complexity: O(N)
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

int maxSum(const vector<int>& A) {
	int N = A.size(), ret = MIN, psum = 0;
	for (int i = 0; i < N; ++i) {
		psum = max(psum, 0) + A[i];
		ret = max(psum, ret);
	}
	return ret;
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

	cout << "Max sum: " << maxSum(A) << endl;
	return 0;
}