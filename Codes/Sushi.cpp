/*
Idex: p.359
Title: Sushi
Description:
The workers are dinning together in the sushi restaurant.
Given budget, prices and preferences, calculate the maximum value of a sum of the preferences to get.
The sushi is offered without limit.

Input:
test case (C<=20)
n(the number of sushi) m(budget)
price 1 preference 1
price 2 preference 2
price 3 preference 3
...
price n preference n

Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define SUSHI_SIZE 20
#define MAX_PRICE 201
using namespace std;
int n, m, price[SUSHI_SIZE], pref[SUSHI_SIZE];
int cache[MAX_PRICE];
int sushi() {
	int ret = 0;
	cache[0] = 0;
	for (int budget = 1; budget <= m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish) {
			if (budget >= price[dish])
				cand = max(cand, cache[(budget - price[dish]) % 201] + pref[dish]);
		}
		cache[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main() {
	int TC;
	freopen("./Inputs/Sushi.txt", "r", stdin);
	cin >> TC;
	for (int testCase = 0; testCase < TC; ++testCase) {
		memset(cache, 0, sizeof(cache));
		cin >> n >> m;
		m /= 100;
		for (int ss = 0; ss < n; ++ss) {
			cin >> price[ss] >> pref[ss];
			price[ss] /= 100;
		}
		cout << sushi() << endl;
	}
	return 0;
}