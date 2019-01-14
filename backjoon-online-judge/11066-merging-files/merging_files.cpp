#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// O(k^3)

int d[501][501];

int FindMinCost(int acc[], int start, int end);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int k;
		cin >> k;
		int acc[k+1];
		acc[0] = 0;
		for (int i = 1; i <= k; ++i) {
			cin >> acc[i];
			acc[i] += acc[i-1];
		}
		cout << FindMinCost(acc, 1, k) << "\n";
		memset(d, 0, (501*501)*sizeof(int));
	}

	return 0;
}

int FindMinCost(int acc[], int i, int j)
{
	if (i == j) return 0;
	if (d[i][j] > 0) return d[i][j];

	d[i][j] = FindMinCost(acc, i, i) + FindMinCost(acc, i+1, j) + acc[j] - acc[i-1];
	for (int k = i+1; k < j; ++k)
		d[i][j] = min(d[i][j], FindMinCost(acc, i, k) + FindMinCost(acc, k+1, j) + acc[j] - acc[i-1]);

	return d[i][j];
}