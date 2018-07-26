/*
Idex: p.201
Title: Fan meeting
Description:
There are n mixed vocal group members and m fans.
When the vocal members stand still and the fans are moving towards right for a handshake,
Calculate the number of cases that they shake hands at the same time
But do not include the cases that hand shake among men

Input:
test case (C<=20)
the gender of the members (M is man, F is woman)
the gender of the fans (M is man, F is woman)

Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int >& b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	return c;
}

// a += b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k) {
	int an = a.size(), bn = b.size();
	a.resize(max(an, bn + k));
	for (int i = 0; i < bn; ++i) {
		a[i + k] += b[i];
	}
}
void subFrom(vector<int>& a, const vector<int>& b) {
	int bn = b.size();

	for (int i = 0; i < bn; ++i) {
		a[i] -= b[i];
	}
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 50) return multiply(a, b);

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
int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();

	vector<int> A(N), B(M);
	for (int i = 0; i < N; ++i) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; ++i) B[M - i - 1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; ++i)
		if (C[i] == 0)
			++allHugs;
	return allHugs;
}

int main() {
	int TC;
	
	freopen("Inputs/FanMeeting.txt", "r", stdin);
	cin >> TC;
	for (int testCase = 0; testCase < TC; ++testCase) {
		string members, fans;
		cin >> members >> fans;
		cout << hugs(members, fans) << endl;
	}
	return 0;
}

