/*
Idex: p.453
Title: Arctic
Time Complexity: O(N^2)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#define MAX_N 101
using namespace std;
int n;
double x, y;

double dist[MAX_N][MAX_N];

double calcDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

bool decision(double d) {
	vector<bool> visited(n, false);
	queue<int> q;
	int seen = 0;
	visited[0] = true;
	q.push(0);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for (int there = 0; there < n; ++there) {
			if (!visited[there] && dist[here][there] <= d){				
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return seen == n;
}

double optimize() {
	double lo = 0, hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (hi + lo) / 2.0;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}

void setDistance(vector<pair<double, double>>& loc) {
	double distance = 0;
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			distance = calcDistance(loc[i].first, loc[i].second, loc[j].first, loc[j].second);
			dist[i][j] = distance;
			dist[j][i] = distance;
		}
	}
}

int main() {
	freopen("Inputs/Arctic.txt", "r", stdin);
	int TC;
	cin >> TC;
	vector<pair<double, double>> loc;
	for (int testCase = 0; testCase < TC; ++testCase) {
		memset(dist, 0, sizeof(dist));
		cin >> n;
		loc.clear();
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			loc.push_back(make_pair(x, y));
		}
		setDistance(loc);
		cout << setprecision(2) << fixed <<optimize() << endl;
	}
	
	return 0;
}