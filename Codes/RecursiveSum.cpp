/*
Idex: p.111
Title: Recursive sum
Description: Given n, add from 1 to n 
Time Complexity: O(N)
*/

#include <iostream>
using namespace std;

int recursiveSum(int n) {
	if (n == 1) return 1;
	return n + recursiveSum(n - 1);
}

int main() {
	int n = 10;
	cout << recursiveSum(n) << endl;
	return 0;
}