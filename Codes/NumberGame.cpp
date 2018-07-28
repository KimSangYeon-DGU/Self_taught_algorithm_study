/*
Idex: p.343
Title: Number Game
Description: 
Given n integers board, A and B play the board game.
the rules of game are that 
first, the player can take the number of left side or right side on the board. and the taken number is removed from the board
second, In the board, there are two numbers, player can remove the two numbers of left or right side.
then, all the numbers are removed, the final score is sum that player take.
Let's calculate the maxinum of subtraction of A score and B score.

Time Complexity: O(N^2)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 55
using namespace std;

int cache[MAX_SIZE][MAX_SIZE];
int board[MAX_SIZE];
int n;
int EMPTY = -987654321;
int play(int left, int right) {
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY) return ret;
	
	// maximum of (score of this turn player - score of next turn player)
	ret = max(board[left] - play(left + 1, right), board[right] - play(left, right-1));

	if (right - left + 1 >= 2) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}
	return ret;
}

void init() {
	for (int i = 0; i < MAX_SIZE; ++i)
		for (int j = 0; j < MAX_SIZE; ++j)
			cache[i][j] = EMPTY;
}

int main() {
	int TC;
	freopen("./Inputs/NumberGame.txt", "r", stdin);
	cin >> TC;

	for (int testCase = 0; testCase < TC; ++testCase) {
		init();
		cin >> n;
		for (int input = 0; input < n; ++input) {
			cin >> board[input];
		}
		cout << play(0, n - 1) << endl;
	}
	return 0;
}