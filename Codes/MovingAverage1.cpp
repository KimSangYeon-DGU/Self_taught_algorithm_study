/*
Idex: p.95
Title: Calculate Moving Average
Description: Given N, let's calculate M months's moving average
Time Complexity: O(N*M)
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

double getRandValue() {
	return rand() % 100 + 1; 
}

vector<double> movingAverage1(const vector<double>& A, int M) {
	vector<double> ret;
	int N = A.size();

	for (int i = M - 1; i < N; i++) {
		// calculate moving average from A[i] to A[i-j]
		double partialSum = 0;
		for (int j = 0; j < M; j++) {
			partialSum += A[i-j];
		}
		ret.push_back(partialSum / M);
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
	vector<double> ret = movingAverage1(value, M);

	// output
	cout << M << " month(s) Moving Average: ";
	for (int i = 0; i < ret.size(); i++) {
		cout << ret.at(i) << " ";
	}
	cout << endl;
	return 0;
}