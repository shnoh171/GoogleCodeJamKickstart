#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int inf = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int d[n+1][n+1];
	int next[n+1][n+1];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
			next[a][b] = b;
		}
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == inf) cout << "0\n";
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == inf || i == j) {
				cout << "0\n";
				continue;
			}

			queue<int> q;
			int curr = i;
			int count = 0;

			while (curr != j) {
				q.push(curr);
				curr = next[curr][j];
				++count;
			}
			q.push(curr);
			++count;
			
			cout << count << ' ';
			while (!q.empty()) {
				cout << q.front() << ' ';
				q.pop();
			}
			cout << '\n';
		}
	}

	return 0;
}
