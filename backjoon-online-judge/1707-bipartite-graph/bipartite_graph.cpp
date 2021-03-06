#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/1707

class UndirectedGraph {
	public:
		UndirectedGraph(int size);
		int GetSize();
		void SortNodes();
		void AddEdge(int node1, int node2);
		bool IsBipartite();
		bool IsPartiallyBipartite(int node, int check[]);

	private:
		int graph_size;
		vector<vector<int> > nodes;
};

int main()
{
	ios_base::sync_with_stdio(false);

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		int v, e;
		cin >> v >> e;

		UndirectedGraph G(v+1);

		for (int j = 0; j < e; ++j) {
			int node1, node2;
			cin >> node1 >> node2;
			G.AddEdge(node1, node2);
		}

		cout << ((G.IsBipartite()) ? "YES" : "NO") << "\n";
	}

	return 0;
}


UndirectedGraph::UndirectedGraph(int size) {
	graph_size = size;
	vector<int> instance;
	for (int i = 0; i < size; ++i) 
		nodes.push_back(instance);
}

int UndirectedGraph::GetSize() {
	return graph_size;
}

void UndirectedGraph::AddEdge(int node1, int node2) {
	nodes[node1].push_back(node2);
	nodes[node2].push_back(node1);
}

void UndirectedGraph::SortNodes() {
	for (int i = 0; i < graph_size; ++i) 
		sort(nodes[i].begin(), nodes[i].end());
}

bool UndirectedGraph::IsBipartite() {
	int check[graph_size]; // 0: not visited, 1: left, 2: right
	fill_n(check, graph_size, 0);

	// start from 1 since 0 is not a valid node in this case
	for (int i = 1; i < graph_size; ++i) {
		if (check[i] == 0) 
			if (!IsPartiallyBipartite(i, check))
				return false;
	}

	return true;
}

bool UndirectedGraph::IsPartiallyBipartite(int node, int check[]) {
	queue<int> q;
	check[node] = 1;
	q.push(node);

	while (q.empty() != true) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < nodes[curr].size(); ++i) {
			int next = nodes[curr][i];
			if (check[next] == 0) {
				check[next] = (check[curr] == 1) ? 2 : 1;
				q.push(next);
			} else if (check[curr] == check[next]) {
				return false;
			}
		}
	}
	return true;
}
