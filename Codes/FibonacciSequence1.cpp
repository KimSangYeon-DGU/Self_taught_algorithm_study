/*
Idex: p.353
Title: Fibonacci Sequence
Description: Calculate fibonacci value at index n
Time Complexity: O(N)
*/

#include <iostream>
using namespace std;

int cache[3];

int fib(int n) {
	if (n <= 1) return n;
	cache[0] = 0, cache[1] = 1;
	for (int i = 2; i <= n; ++i) {
		cache[i % 3] = (cache[(i - 1) % 3] + cache[(i - 2) % 3]) % 100000;
	}
	return cache[n % 3];
}

int main() {
	int n;
	cout << "Index: [0 ... n-1]" << endl;
	cin >> n;
	cout << "The fibonacci value at index "<< n <<" is ";
	cout << fib(n) << endl;
	return 0;
}