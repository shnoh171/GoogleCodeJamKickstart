#include <iostream>
#include <vector>
using namespace std;

bool IsRange(int y, int x, int n) { return y >= 0 && y < n && x >= 0 && x < n; }
long long GetNumberOfWays(int y, int x, const vector<vector<int>> &board, vector<vector<long long>> &d);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	vector<vector<long long>> d(n, vector<long long>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			d[i][j] = -1;
		}
	}

	d[0][0] = 1;
	long long res = GetNumberOfWays(n - 1, n - 1, board, d);
	cout << res << "\n";

	return 0;
}

long long GetNumberOfWays(int y, int x, const vector<vector<int>> &board, vector<vector<long long>> &d)
{
	if (d[y][x] >= 0) return d[y][x];

	long long res = 0;

	for (int i = 0; i < y; ++i)
		if (board[i][x] == y - i)
			res += GetNumberOfWays(i, x, board, d);

	for (int i = 0; i < x; ++i)
		if (board[y][i] == x - i)
			res += GetNumberOfWays(y, i, board, d);

	d[y][x] = res;
	return res;
}