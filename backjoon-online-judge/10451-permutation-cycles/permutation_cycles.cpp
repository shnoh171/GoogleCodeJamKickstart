#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/10451

class DirectedGraph {
	public:
		DirectedGraph(int size);
		int GetSize();
		void SortNodes();
		void AddEdge(int node1, int node2);
		void PrintDfs(int node);
		void PrintBfs(int node);
		int FindNumOfPermutationCycles();
		void CheckPermutationCycle(int node, bool check[]);

	private:
		int graph_size;
		vector<vector<int> > nodes;

		void PrintDfsAux(int node, bool* check);
};

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		
		DirectedGraph G(n+1);
		for (int j = 1; j < n+1; ++j) {
			int node;
			cin >> node;
			G.AddEdge(j, node);
		}

		cout << G.FindNumOfPermutationCycles() << "\n";
	}

	return 0;
}

DirectedGraph::DirectedGraph(int size) {
	graph_size = size;
	vector<int> instance;
	for (int i = 0; i < size; ++i) 
		nodes.push_back(instance);
}

int DirectedGraph::GetSize() {
	return graph_size;
}

void DirectedGraph::AddEdge(int node1, int node2) {
	nodes[node1].push_back(node2);
}

void DirectedGraph::SortNodes() {
	for (int i = 0; i < graph_size; ++i) 
		sort(nodes[i].begin(), nodes[i].end());
}

void DirectedGraph::PrintDfs(int node) {
	bool check[graph_size];
	fill_n(check, graph_size, false);
	PrintDfsAux(node, check);
	cout << "\n";
}

void DirectedGraph::PrintDfsAux(int node, bool* check) {
	check[node] = true;
	cout << node << " ";
	for (int i = 0; i < nodes[node].size(); ++i) {
		int next = nodes[node][i];
		if (check[next] == false) PrintDfsAux(next, check);
	}
}

void DirectedGraph::PrintBfs(int node) {
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

int DirectedGraph::FindNumOfPermutationCycles() {
	bool check[graph_size];
	fill_n(check, graph_size, false);
	int count = 0;

	// Start from 1 since node zero is invalid
	for (int i = 1; i < graph_size; ++i) {
		if (!check[i]) {
			CheckPermutationCycle(i, check);
			++count;
		}
	}

	return count;
}
void DirectedGraph::CheckPermutationCycle(int node, bool check[]) {
	queue<int> q;

	check[node] = true;
	q.push(node);

	while (!q.empty()) {
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
