/*
Idex: p.223
Title: Find string matched to wild card
Description: Given string, let's check if the string matches to wild card
Time Complexity: O(N^3)
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string W, S;
int cache[101][101];
bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];

	if (ret != -1) return ret;

	while (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if (w == W.size())
		return ret = (s == S.size());

	if (W[w] == '*') 
		for (int skip = 0; s + skip <= S.size(); ++skip)
			if (matchMemoized(w + 1, s + skip))
				return ret = 1;
	return ret = 0;
}

int main() {
	W = "*???*c??";
	S = "aaacaa";
	int w = 0, s = 0;
	memset(cache, -1, sizeof(cache));
	cout << matchMemoized(w, s) << endl;

	return 0;
}