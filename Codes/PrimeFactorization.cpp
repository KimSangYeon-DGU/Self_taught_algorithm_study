/*
Idex: p.105
Title: Calculate Prime Factorization
Description: Given n, let's calculate prime factorization of n
Time Complexity: O(size of n), It depends on size of n
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int getRandValue() {
	return rand() % 10000 + 1;
}

vector<int> factor(int n) {
	if (n == 1) return vector<int>(1, 1); // exception when i is equal 1

	vector<int> ret;
	for (int div = 2; n > 1; ++div) {
		while (n % div == 0) {
			n /= div;
			ret.push_back(div);
		}
	}
	return ret;
}

int main() {
	srand((unsigned int)time(NULL));
	int n = getRandValue();
	vector<int> ret = factor(n);
	cout << "n: " << n << endl;
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret.at(i) << " ";
	}
	cout << endl;
	return 0;
}