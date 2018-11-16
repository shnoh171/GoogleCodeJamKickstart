#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/1260

class UndirectedGraph {
	public:
		UndirectedGraph(int size);
		int GetSize();
		void SortNodes();
		void AddEdge(int node1, int node2);
		void PrintDfs(int node);
		void PrintBfs(int node);

	private:
		int graph_size;
		vector<vector<int> > nodes;

		void PrintDfsAux(int node, bool* check);
};

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m, v;
	cin >> n >> m >> v;

	UndirectedGraph G(n+1);
	for (int i = 0; i < m; ++i) {
		int node1, node2;
		cin >> node1 >> node2;
		G.AddEdge(node1, node2);
	}
	G.SortNodes();

	G.PrintDfs(v);
	G.PrintBfs(v);

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

void UndirectedGraph::PrintDfs(int node) {
	bool check[graph_size];
	fill_n(check, graph_size, false);
	PrintDfsAux(node, check);
	cout << "\n";
}

void UndirectedGraph::PrintDfsAux(int node, bool* check) {
	check[node] = true;
	cout << node << " ";
	for (int i = 0; i < nodes[node].size(); ++i) {
		int next = nodes[node][i];
		if (check[next] == false) PrintDfsAux(next, check);
	}
}

void UndirectedGraph::PrintBfs(int node) {
	queue<int> q;
	bool check[graph_size];
	fill_n(check, graph_size, false);

	check[node] = true;
	q.push(node);

	while (q.empty() != true) {
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for (int i = 0; i < nodes[curr].size(); ++i) {
			int next = nodes[curr][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
	cout << "\n";
}
