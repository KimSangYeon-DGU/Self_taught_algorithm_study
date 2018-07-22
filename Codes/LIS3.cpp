/*
Idex: p.234
Title: Longest Increasing Subsequence
Description: Given array A, find the length of LIS
Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> S;
int cache[8+1], n;
int lis(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < S.size(); ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int main() {
	n = 8;
	memset(cache, -1, sizeof(cache));
	S = { 100, 2, 1, 7, 5, 4, 2, 6 };
	cout << lis(-1) - 1 << endl;
	return 0;
}