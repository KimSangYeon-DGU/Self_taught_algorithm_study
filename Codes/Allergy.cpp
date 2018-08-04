#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/*
canEat - set of possible foods that can eat friend i
eaters - set of possible friends that can eat food i
edible - the number of foods who can eat friend i in selected foods
*/ 

int INF = 987654321;
int n, m, t, best;
vector<int> canEat[50], eaters[50];

void search(vector<int>& edible, int chosen) {
	//prunning
	if (chosen >= best) return;

	int first = 0;
	while (first < n && edible[first] > 0) 
		++first; 

	// there are no foods that can eat for friends
	if (first == n) {
		best = chosen;
		return;
	}

	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];

		for (int j = 0; j < eaters[food].size(); ++j) 
			edible[eaters[food][j]]++;
		
		search(edible, chosen + 1);

		for (int j = 0; j < eaters[food].size(); ++j) 
			edible[eaters[food][j]]--;
		
	}
}

void init() {
	for (int i = 0; i < 50; i++) {
		canEat[i].clear();
		eaters[i].clear();
	}
}

int main() {
	freopen("./Inputs/Allergy.txt", "r", stdin);
	int TC;
	cin >> TC;

	for (int testCase = 0; testCase < TC; ++testCase) {
		init();
		map<string, int> friendsIndex;
		string name;
		best = INF;
		cin >> n >> m;
		
		for (int i = 0; i < n; ++i) {
			cin >> name;
			friendsIndex[name] = i;
		}

		for (int i = 0; i < m; ++i) {
			cin >> t;
			for (int j = 0; j < t; ++j) {
				cin >> name;
				canEat[friendsIndex[name]].push_back(i);
				eaters[i].push_back(friendsIndex[name]);
			}
		}
		vector<int> edible(n, 0);

		search(edible, 0);

		cout << best << endl;
	}
	return 0;
}