#include <iostream>
#include <vector>
#include <algorithm>
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
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] == inf) cout << "0 ";
			else cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
