#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 987654321;
int FindMinCost(int i, int j, pair<int, int> msize[], vector<vector<int>> &d);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	pair<int, int> msize[n];
	for (int i = 0; i < n; ++i)
		cin >> msize[i].first >> msize[i].second;

	vector<vector<int>> d(n, vector<int>(n, inf));
	for (int i = 0; i < n; ++i) d[i][i] = 0;

	cout << FindMinCost(0, n-1, msize, d) << "\n";

	return 0;
}

int FindMinCost(int i, int j, pair<int, int> msize[], vector<vector<int>> &d)
{
	if (d[i][j] < inf) return d[i][j];

	for (int k = i; k < j; ++k) {
		int left = FindMinCost(i, k, msize, d);
		int right = FindMinCost(k+1, j, msize, d);
		int curr = msize[i].first * msize[k].second * msize[j].second;
		d[i][j] = min(d[i][j], left + right + curr);
	}
	return d[i][j];
}
