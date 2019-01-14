#include <iostream>
#include <algorithm>
#include <cstring>
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

	for (int i = 1; i <= n ;++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = inf;
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
	}


	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n ; ++i) {
			for (int j = 1; j <= n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	pair<int, int> knum[n+1];
	for (int i = 1; i <= n; ++i) {
		knum[i].second = i;
		for (int j = 1; j <= n ; ++j) {
			knum[i].first += d[i][j];
		}
	}

	sort(knum+1, knum+n+1);
	cout << knum[1].second << "\n";

	return 0;
}
