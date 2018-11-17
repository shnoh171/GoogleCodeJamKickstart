#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/11724

class UndirectedGraph {
	public:
		UndirectedGraph(int size);
		int GetSize();
		void SortNodes();
		void AddEdge(int node1, int node2);
		void CheckConnectedComponents(int node, bool* check);

	private:
		int graph_size;
		vector<vector<int> > nodes;
};

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	UndirectedGraph G(n+1);

	for (int i = 0; i < m; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		G.AddEdge(node1, node2);
	}

	bool check[n+1];
	fill_n(check, n+1, false);

	int cnt = 0;
	for (int i = 1; i < n+1; ++i) {
		if (check[i] == false) {
			++cnt;
			G.CheckConnectedComponents(i, check);
		}
	}

	cout << cnt << "\n";

	return 0;
}

UndirectedGraph::UndirectedGraph(int size) {
	graph_size = size;
	nodes.reserve(size);
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

void UndirectedGraph::CheckConnectedComponents(int node, bool* check) {
	queue<int> q;

	check[node] = true;
	q.push(node);

	while (q.empty() != true) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < nodes[curr].size(); ++i) {
			int next = nodes[curr][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
