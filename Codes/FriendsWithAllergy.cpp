/*
Idex: p.103
Title: Find the minimum number of foods
Description: Finding the minimum number of foods for all the friends to eat 
Time Complexity: O(M*N*2^M)
Input:
	TC
	N friends, M foods
	o x o x.... if o, first friend can eat the food, and if x, first friend can't eat the food.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX_SIZE 20
using namespace std;
const int INF = 987654321;
int N, M; // N friends, M foods

int checkList[MAX_SIZE][MAX_SIZE];
bool canEverybodyEat(const vector<int>& menu) {
	if (menu.size() == 0)
		return false;
	else {
		for (int frd = 0; frd < N; ++frd) {
			int check = checkList[frd][menu[0]];
			for (int mn = 1; mn < menu.size(); ++mn) {
				check |= checkList[frd][menu[mn]];
			}
			if (check == 0)
				return false;
		}
		return true;
	}
}

int selectMenu(vector<int>& menu, int food) {
	if (food == M) return (canEverybodyEat(menu)) ? menu.size() : INF;
	int ret = selectMenu(menu, food + 1);
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}

int main() {
	int TC;
	freopen("./Inputs/FriendsWithAllergy.txt", "r", stdin);
	cin >> TC;
	for (int testCase = 0; testCase < TC; ++testCase) {
		memset(checkList, 0, sizeof(checkList));
		vector<int> menu;
		cin >> N >> M;
		char input;

		// input 
		for (int n = 0; n < N; ++n) {
			for (int m = 0; m < M; ++m) {
				cin >> input;
				if (input == 'o')
					checkList[n][m] = 1;
				else if (input == 'x')
					checkList[n][m] = 0;
			}
		}

		// calcualte
		int ret = selectMenu(menu, 0);
		if (ret != INF)
			cout << ret << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}