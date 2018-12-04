#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/1939

class UndirectedGraph {
	public:
		UndirectedGraph(int size);
		int GetSize();
		void SortNodes();
		void AddEdge(int node1, int node2, int weight);
		bool CanDeliver(int from, int to, int weight);

	private:
		int graph_size;
		vector<vector<pair<int, int> > > nodes;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int min_val = 0;
	int max_val = 0;
	cin >> n >> m;
	UndirectedGraph country(n+1);
	
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		max_val = max(max_val, c);
		country.AddEdge(a, b, c);
	}
	country.SortNodes();

	int from, to;
	cin >> from >> to;

	int left = min_val;
	int right = max_val;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (country.CanDeliver(from, to, mid)) {
			ans = max(ans, mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}

UndirectedGraph::UndirectedGraph(int size) {
	graph_size = size;
	vector<pair<int, int> > instance;
	for (int i = 0; i < size; ++i) 
		nodes.push_back(instance);
}

int UndirectedGraph::GetSize() {
	return graph_size;
}

void UndirectedGraph::AddEdge(int node1, int node2, int weight) {
	nodes[node1].push_back(make_pair(node2, weight));
	nodes[node2].push_back(make_pair(node1, weight));
}

void UndirectedGraph::SortNodes() {
	for (int i = 0; i < graph_size; ++i) 
		sort(nodes[i].begin(), nodes[i].end());
}

bool UndirectedGraph::CanDeliver(int from, int to, int weight)
{
	queue<int> q;
	bool check[graph_size];
	fill_n(check, graph_size, false);

	check[from] = true;
	q.push(from);

	while (q.empty() != true) {
		int curr = q.front();
		q.pop();

		if (curr == to)
			return true;

		for (int i = 0; i < nodes[curr].size(); ++i) {
			int next = nodes[curr][i].first;
			if (check[next] == false && nodes[curr][i].second >= weight) {
				check[next] = true;
				q.push(next);
			}
		}
	}

	return false;
}
