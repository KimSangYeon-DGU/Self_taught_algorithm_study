/*
Idex: p.227
Title: Find max sum in triangle
Description: Given a triangle number, find max sum, but only you can go down or right down from current position.
Time Complexity: O(2^n-1)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_NUMBER 10
#define MAX_SIZE 5
using namespace std;

int n, triangle[MAX_SIZE][MAX_SIZE];
int cache[MAX_SIZE][MAX_SIZE][MAX_NUMBER * MAX_SIZE + 1];

int path(int y, int x, int sum) {
	if (y == n - 1) return sum + triangle[y][x];

	int& ret = cache[y][x][sum];
	
	if (ret != -1) return ret;

	sum += triangle[y][x];

	return ret = max(path(y + 1, x, sum), path(y + 1, x + 1, sum));
}

int main() {
	/*
	6
	1 2
	3 7 4
	9 4 1 7
	2 7 5 9 4
	*/
	n = MAX_SIZE;
	triangle[0][0] = 6;
	triangle[1][0] = 1, triangle[1][1] = 2;
	triangle[2][0] = 3, triangle[2][1] = 7, triangle[2][2] = 4;
	triangle[3][0] = 9, triangle[3][1] = 4, triangle[3][2] = 1, triangle[3][3] = 7;
	triangle[4][0] = 2, triangle[4][1] = 7, triangle[4][2] = 5, triangle[4][3] = 9, triangle[4][4] = 4;
	memset(cache, -1, sizeof(cache));
	cout << path(0, 0, 0) << endl;
	return 0;
}