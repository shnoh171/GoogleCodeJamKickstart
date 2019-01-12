#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

bool IsRange(int y, int x, int m, int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	int map[m][n];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> map[i][j];

	int number[m][n];
	bool check[m][n];
	memset(number, 0, (m*n)*sizeof(int));
	memset(check, false, (m*n)*sizeof(bool));
	priority_queue<tuple<int, int, int>> q;
	
	number[0][0] = 1;
	q.push(make_tuple(map[0][0], 0, 0));

	while (!q.empty()) {
		tuple<int, int, int> curr = q.top();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int curr_num, y, x;
			tie(curr_num, y, x) = curr;
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (IsRange(next_y, next_x, m, n) && map[next_y][next_x] < map[y][x]) {
				number[next_y][next_x] += number[y][x];
				if (!check[next_y][next_x]) {
					check[next_y][next_x] = true;
					q.push(make_tuple(map[next_y][next_x], next_y, next_x));
				}
			}
		}
	}
	
	cout << number[m-1][n-1] << "\n";

	return 0;
}

bool IsRange(int y, int x, int m, int n)
{
	return y >= 0 && y < m && x >= 0 && x < n;
}