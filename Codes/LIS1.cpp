/*
Idex: p.232
Title: Longest Increasing Subsequence
Description: Given array A, find the length of LIS
Time Complexity: O(N^3)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lis(const vector<int>& A) {
	if (A.empty()) return 0;

	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); ++j)
			if (A[i] < A[j])
				B.push_back(A[j]);
		ret = max(ret, 1 + lis(B));
	}
	return ret;
}

int main() {
	vector<int> A{3, 2, 1, 7, 5, 4, 2, 6};
	cout << lis(A) << endl;
	return 0;
}