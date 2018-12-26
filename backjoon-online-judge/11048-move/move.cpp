#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maze[1001][1001];
int d[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> maze[i][j];
	
	d[1][1] = maze[1][1];
	for (int i = 2; i <= n; ++i)
		d[i][1] = d[i - 1][1] + maze[i][1];
	for (int j = 2; j <= m; ++j)
		d[1][j] = d[1][j - 1] + maze[1][j];

	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j)
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + maze[i][j];
	
	cout << d[n][m] << "\n";

	return 0;
}
