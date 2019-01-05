#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DirectedGraph {
public:
	DirectedGraph(int size);
	int GetSize();
	void AddEdge(int node1, int node2);

	void PrintTopologicalSort();

private:
	int graph_size;
	vector<vector<int>> nodes;

	vector<int> in_degree;
	queue<int> q;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	DirectedGraph g(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		g.AddEdge(a, b);
	}

	g.PrintTopologicalSort();

	return 0;
}

DirectedGraph::DirectedGraph(int size)
{
	graph_size = size;
	vector<int> instance;
	for (int i = 0; i < size + 1; ++i) {
		nodes.push_back(instance);
		in_degree.push_back(0);
	}
		
}

int DirectedGraph::GetSize()
{
	return graph_size;
}

void DirectedGraph::AddEdge(int node1, int node2)
{
	nodes[node1].push_back(node2);
	++in_degree[node2];
}

void DirectedGraph::PrintTopologicalSort()
{
	for (int i = 1; i <= graph_size; ++i) {
		if (!in_degree[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		cout << curr << " ";

		for (int i = 0; i < nodes[curr].size(); ++i) {
			int next = nodes[curr][i];
			if (!(--in_degree[next]))
				q.push(next);
		}
	}

	cout << "\n";
}