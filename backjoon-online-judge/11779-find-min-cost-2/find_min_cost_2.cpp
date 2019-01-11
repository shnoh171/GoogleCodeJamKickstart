#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
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

	int n, m;
	cin >> n >> m;

	vector<edge> city[n+1];
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		city[from].push_back(edge(to, cost));
	}

	int start, end;
	cin >> start >> end;

	int dist[n+1];
	bool check[n+1];
	int prev[n+1];
	for (int i = 1; i <= n; ++i) dist[i] = inf;
	memset(check, false, (n+1)*sizeof(bool));

	dist[start] = 0;
	for (int i = 0; i < n; ++i) {
		int curr;
		int val = inf;
		for (int j = 1; j <= n; ++j) {
			if (!check[j] && dist[j] < val) {
				curr = j;
				val = dist[j];
			}
		}
		if (val == inf) break;
		check[curr] = true;
		for (auto x : city[curr]) {
			if (dist[x.to] > dist[curr] + x.cost) {
				dist[x.to] = dist[curr] + x.cost;
				prev[x.to] = curr;
			}
		}
	}
	
	cout << dist[end] << "\n";

	int count = 1;
	vector<int> opt;
	opt.push_back(end);
	
	int curr = end;
	while (curr != start) {
		++count;
		curr = prev[curr];
		opt.push_back(curr);
	}

	cout << count << "\n";
	for (int i = opt.size()-1; i >= 0; --i)
		cout << opt[i] << " ";
	cout << "\n";

	return 0;
}
