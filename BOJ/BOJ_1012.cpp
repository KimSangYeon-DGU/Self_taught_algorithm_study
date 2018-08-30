#include <iostream>
#include <cstring>
#include <queue>
#define MAX_N 51
using namespace std;

int worm_num;
int M, N, K;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool isInRange(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;
	if (visited[y][x] == true || map[y][x] == 0)
		return false;
	return true;
}

void find(int x, int y) {
	queue<pair<int, int>> q; 
	int cur_x, cur_y, next_x, next_y;
	q.push(make_pair(x, y));
	visited[y][x] = true;
	while(!q.empty()){
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			next_x = cur_x + dx[d];
			next_y = cur_y + dy[d];
			if (isInRange(next_x, next_y)) {
				q.push(make_pair(next_x, next_y));
				visited[next_y][next_x] = true;
			}
		}
	}
}

int main() {
	//freopen("./Inputs/BOJ_1012.txt", "r", stdin);
	int TC; 
	cin >> TC;
	for (int testCase = 0; testCase < TC; ++testCase) {
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		worm_num = 0;
		cin >> M >> N >> K;
		int m, n;
		for (int k = 0; k < K; ++k) {
			cin >> m >> n;
			map[n][m] = 1;
		}
		for (n = 0; n < N; ++n) {
			for (m = 0; m < M; ++m) {
				if (map[n][m] == 1 && visited[n][m] == false) {
					find(m, n);
					++worm_num;
				}
			}
		}
		cout << worm_num << endl;
	}

	return 0;
}