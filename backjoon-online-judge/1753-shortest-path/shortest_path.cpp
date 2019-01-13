#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int inf = 987654321;

struct edge {
	int to;
	int cost;
	edge(int t, int c) { to = t; cost = c; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;
	vector<edge> g[v+1];
	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(edge(v, w));
	}

	int dist[v+1];
	bool check[v+1];
	for (int i = 1; i <= v; ++i) dist[i] = inf;
	memset(check, false, (v+1)*sizeof(bool));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[k] = 0;
	pq.push(pair<int,int>(dist[k], k));

	while (!pq.empty()) {
		int curr = pq.top().second;
		pq.pop();

		if (check[curr]) continue;
		check[curr] = true;

		for (auto x : g[curr]) {
			dist[x.to] = min(dist[x.to], dist[curr] + x.cost);
			pq.push(pair<int,int> (dist[x.to], x.to));
		}
	}

	for (int i = 1; i <= v; ++i) {
		if (i == k) cout << "0\n";
		else if (dist[i] == inf) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}