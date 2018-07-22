/*
Idex: p.239
Title: Joined Longest Increasing Subsequence
Description: Given two arrays A and B, find the length of LIS(A + B)
for example, A: 1, 2, 4, B: 3, 4, 7
JLIS: 1, 2, 3, 4, 7 => 5

Time Complexity: O(N^3)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB) {
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;
	ret = 2;
	long long a = ((indexA == -1) ? NEGINF : A[indexA]);
	long long b = ((indexB == -1) ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);
	
	for (int nextB = indexB + 1; nextB < m; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	
	return ret;
}

int main() {
	memset(cache, -1, sizeof(cache));
	n = 3, m = 3;
	A[0] = 1, A[1] = 2, A[2] = 3;
	B[0] = 4, B[1] = 5, B[2] = 6;
	cout << jlis(-1, -1) - 2 << endl;
	return 0;
}