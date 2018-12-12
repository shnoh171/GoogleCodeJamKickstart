#include <iostream>
using namespace std;

int Find(int element, int set[], int size);
void Union(int element1, int element2, int set[], int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int set[n+1];
	for (int i = 0; i < n+1; ++i)
		set[i] = i;

	for (int i = 0; i < m; ++i) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 0) {
			Union(a, b, set, n+1);
		} else if (cmd == 1) {
			if (Find(a, set, n+1) == Find(b, set, n+1))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}

int Find(int element, int set[], int size)
{
	if (set[element] == element) {
		return element;
	} else {
		int root = Find(set[element], set, size);
		set[element] = root;
		return root;
	}
}

void Union(int element1, int element2, int set[], int size)
{
	int root1 = Find(element1, set, size);
	int root2 = Find(element2, set, size);

	set[root1] = root2;
}

