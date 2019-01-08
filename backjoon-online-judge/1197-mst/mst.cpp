#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int Find(int element, int set[]);
void Union(int element1, int element2, int set[]);

struct edge {
	int node1;
	int node2;
	int weight;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int nodes[v+1];
	for (int i = 1; i < v+1; ++i) nodes[i] = i;

	edge edges[e];
	for (int i = 0; i < e; ++i)
		cin >> edges[i].node1 >> edges[i].node2 >> edges[i].weight;
	sort(edges, edges+e, [](edge n1, edge n2) { return n1.weight < n2.weight; });

	long long res = 0;
	for (int i = 0; i < e; ++i) {
		int set1 = Find(edges[i].node1, nodes);
		int set2 = Find(edges[i].node2, nodes);
		if (set1 != set2) {
			Union(edges[i].node1, edges[i].node2, nodes);
			res += edges[i].weight;
		}
	}

	cout << res << "\n";

	return 0;
}

int Find(int element, int set[])
{
	if (set[element] == element)
		return element;
	else
		return set[element] = Find(set[element], set);
}

void Union(int element1, int element2, int set[])
{
	int root1 = Find(element1, set);
	int root2 = Find(element2, set);
	set[root1] = root2;
}
