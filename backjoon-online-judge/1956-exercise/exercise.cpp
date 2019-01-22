#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 987654321;

struct route {
	int from;
	int to;
	int length;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	int dist[v+1][v+1];
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}
	
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= v; ++k) {
		for (int i = 1; i <= v; ++i) {
			for (int j = 1; j <= v; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int res = inf;
	for (int i = 1; i <= v; ++i) {
		for (int j = 1; j <= v; ++j) {
			if (i != j && dist[i][j] < inf && dist[j][i] < inf) {
				res = min(res, dist[i][j] + dist[j][i]);
			}
		}
	}

	cout << (res < inf ? res : -1) << "\n";

	return 0;
}
