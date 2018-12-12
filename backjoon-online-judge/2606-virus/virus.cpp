#include <iostream>
using namespace std;

int Find(int element, int computers[], int size);
void Union(int element1, int element2, int computers[], int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int computers[n+1];
	for (int i = 1; i < n+1; ++i) computers[i] = i;

	for (int i = 0; i < m; ++i) {
		int element1, element2;
		cin >> element1 >> element2;
		Union(element1, element2, computers, n+1);
	}

	int count = 0;
	for (int i = 2; i < n+1; ++i)
		if (Find(i, computers, n+1) == Find(1, computers, n+1))
			++count;

	cout << count << "\n";

	return 0;
}

int Find(int element, int computers[], int size)
{
	if (computers[element] == element)
		return element;
	else
		return computers[element] = Find(computers[element], computers, size);
}

void Union(int element1, int element2, int computers[], int size)
{
	int root1 = Find(element1, computers, size);
	int root2 = Find(element2, computers, size);
	computers[root1] = root2;
}
