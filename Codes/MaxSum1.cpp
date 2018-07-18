/*
Idex: p.117
Title: Max sum
Description: Given array A, calculate maximum sum of sub-array in array A
Time Complexity: O(N^3)
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
	int N = A.size(), ret = MIN;
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			int sum = 0;
			for (int k = i; k <= j; ++k)
				sum += A[k];
			ret = max(ret, sum);
		}
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