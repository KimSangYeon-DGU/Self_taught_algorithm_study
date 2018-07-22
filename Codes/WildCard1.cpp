/*
Idex: p.222
Title: Find string matched to wild card
Description: Given string, let's check if the string matches to wild card
Time Complexity: O(N^3)
*/

#include <iostream>
#include <string>
using namespace std;

bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
		++pos;

	if (pos == w.size())
		return pos == s.size();

	if (w[pos] == '*')
		for (int skip = 0; pos + skip <= s.size(); ++skip)
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
	return false;
}

int main() {
	string w = "*c*";
	string s = "aaacaa";
	cout << match(w, s) << endl;
	
	return 0;
}