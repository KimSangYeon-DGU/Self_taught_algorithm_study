/*
Idex: p.95
Title: Calculate Moving Average
Description: Given N, let's calculate M months's moving average
Time Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

double getRandValue() {
	return rand() % 100 + 1;
}

vector<double> movingAverage2(const vector<double>& A, int M) {
	vector<double> ret;
	int N = A.size();
	double partialSum = 0;
	for (int i = 0; i < M - 1; i++) {
		partialSum += A[i];
	}

	for (int i = M - 1; i < N; i++) {
		// calculate moving average from A[i] to A[i-j]
		partialSum += A[i];
		ret.push_back(partialSum / M);
		partialSum -= A[i - M + 1];
	}
	return ret;
}

int main() {
	int N = 12;
	int M = 3;
	srand((unsigned int)time(NULL));
	vector<double> value;

	// input
	for (int i = 0; i < N; i++) {
		value.push_back(getRandValue());
	}

	// calculate
	vector<double> ret = movingAverage2(value, M);

	// output
	cout << M << " month(s) Moving Average: ";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i) << " ";
	}
	cout << endl;
	return 0;
}