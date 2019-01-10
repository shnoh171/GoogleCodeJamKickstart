#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// Dijkstra's algorithm: O(|V|^2) implementation

const int inf = 987654321;

struct edge {
	int to;
	int weight;
	edge(int t, int w) { to = t; weight = w; }
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<edge> city[n+1];
	for (int i = 0; i < m; ++i) {
		int n1, n2, w;
		cin >> n1 >> n2 >> w;
		city[n1].push_back(edge(n2, w));
	}

	int start, end;
	cin >> start >> end;

	int dist[n+1];
	for (int i = 1; i <= n; ++i) dist[i] = inf;
	bool check[n+1];
	memset(check, false, (n+1)*sizeof(bool));
	
	dist[start] = 0;
	for (int i = 0; i < n; ++i) {
		int curr;
		int val = inf;
		for (int j = 1; j < n+1; ++j) {
			if (!check[j] && dist[j] < val) {
				val = dist[j];
				curr = j;
			}
		}

		check[curr] = true;

		for (auto x : city[curr]) {
			dist[x.to] = min(dist[x.to], dist[curr] + x.weight);
		}
	}

	cout << dist[end] << "\n";

	return 0;
}
