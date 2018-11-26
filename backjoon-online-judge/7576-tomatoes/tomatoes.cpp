#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/7576

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int main()
{
	ios_base::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	int tomatoes[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> tomatoes[i][j];

	int dist[n][m];
	queue<pair<int, int> > q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tomatoes[i][j] == 1) {
				dist[i][j] = 0;
				q.push(make_pair(i, j));
			} else {
				dist[i][j] = m * n + 1;
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int next_y = y + dy[k];
			int next_x = x + dx[k];

			if (next_y >= 0 && next_y < n && next_x >= 0 && next_x < m &&
					tomatoes[next_y][next_x] == 0 && dist[next_y][next_x] > dist[y][x] + 1) {
				dist[next_y][next_x] = dist[y][x] + 1;
				q.push(make_pair(next_y, next_x));
			}
		}
	}

	/*
	cout << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	int max_val = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (tomatoes[i][j] != -1)
				max_val = max(max_val, dist[i][j]);
		}
	}

	if (max_val == m * n + 1) cout << "-1\n";
	else cout << max_val << "\n";

	return 0;
}
