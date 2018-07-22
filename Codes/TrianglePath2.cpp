/*
Idex: p.229
Title: Find max sum in triangle
Description: Given a triangle number, find max sum, but only you can go down or right down from current position.
Time Complexity: O(n^2)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_NUMBER 10
#define MAX_SIZE 5
using namespace std;

int n, triangle[MAX_NUMBER][MAX_NUMBER];
int cache[MAX_NUMBER][MAX_NUMBER];

int path(int y, int x) {
	if (y == n - 1) return triangle[y][x];

	int& ret = cache[y][x];

	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}
int main() {
	/*
	1
	2 4
	8 16 8
	32 64 32 64
	128 256 128 256 128
	*/
	n = MAX_SIZE;
	triangle[0][0] = 1;
	triangle[1][0] = 2, triangle[1][1] = 4;
	triangle[2][0] = 8, triangle[2][1] = 16, triangle[2][2] = 8;
	triangle[3][0] = 32, triangle[3][1] = 64, triangle[3][2] = 32, triangle[3][3] = 64;
	triangle[4][0] = 128, triangle[4][1] = 256, triangle[4][2] = 128, triangle[4][3] = 256, triangle[4][4] = 128;
	memset(cache, -1, sizeof(cache));
	cout << path(0, 0) << endl;
	return 0;
}