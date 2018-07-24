/*
Idex: p.159
Title: Pair two chidren
Description: In kindergarten, the children go picnic. 
The teacher wants children not to fight, so he or she decided to pair them friends.
What is the number of pair?
input
TC: test case
n: the number of children 
m: the number of friend pair

Time Complexity: O(N)
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
bool areFriends[10][10];

int countParings(bool taken[10]) {
	int firstFree = -1;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	int TC = 0;
	freopen("Inputs/Picnic.txt", "r", stdin);
	cin >> TC;
	
	for (int testCase = 0; testCase < TC; ++testCase) {
		cin >> n >> m;
		int a, b;
		bool taken[10];
		memset(areFriends, 0, sizeof(areFriends));
		memset(taken, false, sizeof(taken));

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			areFriends[a][b] = 1;
			areFriends[b][a] = 1;
		}
		cout << countParings(taken) << endl;
	}

	return 0;
}