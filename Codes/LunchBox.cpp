/*
Idex: p.376

Title: Heat lunch box

Description: 
Calculate minimum time to eat all of lunch box
There is only one microwave, and you should heat the lunch box before eating it.
Time Complexity: O(N)

Input:
Test case
the number of lunch box
n time to heat
n time to eat

Variables:
m: time to heat
e: time to eat
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX_N 10010
using namespace std;

int n, e[MAX_N], m[MAX_N];

int heat() {
	vector<pair<int, int>> order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(-e[i], m[i]));
	}
	sort(order.begin(), order.end());

	int beginEat = 0, ret = 0;
	for (int i = 0; i < n; ++i) {
		beginEat += order[i].second;
		ret = max(ret, beginEat - order[i].first);
	}
	return ret;
}

int main() {
	//freopen("./Inputs/LunchBox.txt", "r", stdin);
	int TC;
	cin >> TC;
	for (int testCase = 0; testCase < TC; ++testCase) {
		memset(e, 0, sizeof(e));
		memset(m, 0, sizeof(m));
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> m[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> e[i];
		}
		cout << heat() << endl;
	}
	return 0;
}