/*
Idex: p.187
Title: Karatsuba Algorithm
Description: Multiply two big numbers using Karatsuba algorithm 
Time Complexity: O(n^log3)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void normalize(vector<int>& num) {
	num.push_back(0);

	for (int i = 0; i < num.size() - 1; ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}

	while (num.size() > 1 && num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int >& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

// a += b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + k));
	a.push_back(0);
	for (int i = 0; i < bn; ++i) {
		a[i + k] += b[i];
	}
	normalize(a);
}
void subFrom(vector<int>& a, const vector<int>& b) {
	int bn = b.size();

	for (int i = 0; i < bn; ++i) {
		a[i] -= b[i];
	}
	normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 2) return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z0 = karatsuba(a0, b0);
	vector<int> z2 = karatsuba(a1, b1);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);

	return ret;
}

int main() {
	vector<int> a;
	vector<int> b;

	//529212381234 * 5678;
	a.push_back(4); a.push_back(3); a.push_back(2); a.push_back(1); a.push_back(8); a.push_back(3); 
	a.push_back(2); a.push_back(1); a.push_back(2); a.push_back(9); a.push_back(2); a.push_back(5);

	b.push_back(8); b.push_back(7); b.push_back(6); b.push_back(5);

	vector<int> c = karatsuba(a, b);
	for (int i = c.size() - 1; i >= 0; --i) {
		cout << c.at(i);
	}
	cout << endl;
	return 0;
}