#include <iostream>
#include <algorithm>
using namespace std;

// Incomplete: need to be solved after BOJ fix the problem.

const int inf = 987654321;

struct edge {
	int from;
	int to;
	int weight;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;

		edge path[2*m];
		edge wormhole[w];
		for (int i = 0; i < m; ++i) {
			int s, e, t;
			cin >> s >> e >> t;
			path[2*i].from = path[2*i+1].to = s;
			path[2*i].to = path[2*i+1].from = e;
			path[2*i].weight = path[2*i+1].weight = t;
		}
		for (int i = 0; i < w; ++i) {
			cin >> wormhole[i].from >> wormhole[i].to >> wormhole[i].weight;
		}

		int dist[n+1];
		dist[1] = 0;
		for (int i = 2; i <= n; ++i) dist[i] = inf;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2*m-1; ++j) {
				int from = path[j].from;
				int to = path[j].to;
				int time = path[j].weight;
				if (dist[from] < inf)
					dist[to] = min(dist[to], dist[from] + time);
			}
			for (int j = 0; j < w; ++j) {
				int from = wormhole[j].from;
				int to = wormhole[j].to;
				int time = -1 * wormhole[j].weight;
				if (dist[from] < inf)
					dist[to] = min(dist[to], dist[from] + time);
			}
		}

		bool flag = false;
		for (int i = 1; i <= n; ++i) {
			if (dist[i] < 0) {
				cout << "YES\n";
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";
		}
	}

	return 0;
}
