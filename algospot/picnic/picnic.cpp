#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int getNumberOfCombinations(vector<bool> &taken, vector<vector<int>> &friends, int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
		int n, m;
		cin >> n >> m;
		vector<bool> taken(n);
		vector<vector<int>> friends(n);

		while (m--) {
			int a, b;
			cin >> a >> b;
			friends[min(a, b)].push_back(max(a, b));
		}

		cout << getNumberOfCombinations(taken, friends, n) << "\n";
	}

	return 0;
}

int getNumberOfCombinations(vector<bool> &taken, vector<vector<int>> &friends, int size)
{
	int ret = 0;
	int smallest = 0;
	while (smallest < size && taken[smallest]) {
		++smallest;
	}
	if (smallest == size) return 1;


	for (int i = 0; i < friends[smallest].size(); ++i) {
		int next = friends[smallest][i];
		if (!taken[next]) {
			taken[smallest] = true;
			taken[next] = true;
			ret += getNumberOfCombinations(taken, friends, size);
			taken[smallest] = false;
			taken[next] = false;
		}
	}

	return ret;
}