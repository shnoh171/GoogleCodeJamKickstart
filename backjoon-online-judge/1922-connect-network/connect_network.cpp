#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void AddEdge(int node1, int node2, int weight, vector<pair<int,int>> computer[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int,int>> computer[n+1];

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		AddEdge(a, b, c, computer);
	}

	bool check[n+1];
	memset(check, false, (n+1)*sizeof(bool));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	check[1] = true;
	for (auto x : computer[1])
		pq.push(x);

	int cost = 0;
	while (!pq.empty()) {
		pair<int, int> curr = pq.top();
		int weight = curr.first;
		int next = curr.second;
		pq.pop();

		if (!check[next]) {
			cost += weight;
			check[next] = true;
			for (auto x : computer[next])
				pq.push(x);
		}
	}
	
	cout << cost << "\n";

	return 0;
}

void AddEdge(int node1, int node2, int weight, vector<pair<int,int>> computer[])
{
	computer[node1].push_back(pair<int, int>(weight, node2));
	computer[node2].push_back(pair<int, int>(weight, node1));
}