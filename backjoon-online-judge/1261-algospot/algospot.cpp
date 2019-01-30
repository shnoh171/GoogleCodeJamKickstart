#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int inf = 987654321;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

bool IsRange(int y, int x, int n, int m);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> m >> n;
	int map[n][m], dist[n][m];
	bool check[n][m];
	memset(check, false, n*m*sizeof(bool));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {	
			map[i][j] = s[j] - '0';
			dist[i][j] = inf;
		}
	}

	priority_queue<
		tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>
	> pq;

	dist[0][0] = 0;
	pq.push(make_tuple(0, 0, 0));

	while (!pq.empty()) {
		tuple<int, int, int> curr = pq.top();
		int y = get<1>(curr);
		int x = get<2>(curr);
		pq.pop();
		
		if (check[y][x]) continue;
		check[y][x] = true;
		
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (IsRange(ny, nx, n, m)) {
				dist[ny][nx] = min(dist[ny][nx], dist[y][x] + map[y][x]);
				pq.push(make_tuple(dist[ny][nx], ny, nx));
			}
		}
	}

	cout << dist[n-1][m-1] << "\n";

	return 0;
}

bool IsRange(int y, int x, int n, int m) {
	return y >= 0 && y < n && x >= 0 && x < m;
}