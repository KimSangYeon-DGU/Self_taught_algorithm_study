/*
Idex: p.233
Title: Longest Increasing Subsequence
Description: Given array A, find the length of LIS
Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S;
int cache[8], n;
int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < S.size(); ++next) {
		if (S[start] < S[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int main() {
	n = 8;
	memset(cache, -1, sizeof(cache));
	S = { 100, 2, 1, 7, 5, 4, 2, 6 };
	
	int maxLen = 0;
	for (int begin = 0; begin < n; ++begin) {
		maxLen = max(maxLen, lis(begin));
	}
	cout << maxLen << endl;
	return 0;
}