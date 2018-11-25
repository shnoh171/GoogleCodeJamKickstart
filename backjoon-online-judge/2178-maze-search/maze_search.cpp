#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/2178

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int FindDistance(vector<vector<int> >& maze);
bool IsRange(int y, int x, int y_size, int x_size);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > maze(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			maze[i][j] = s[j] - '0';
		}
	}

	cout << FindDistance(maze) << "\n";

	return 0;
}

int FindDistance(vector<vector<int> >& maze) 
{
	queue<pair<int, int> > q;
	int y_size = maze.size();
	int x_size = maze[0].size();
	int distance[y_size][x_size] = {};

	distance[0][0] = 1;
	q.push(make_pair(0, 0));

	while (q.empty() != true) {
		pair<int, int> position = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int y = position.first + dy[i];
			int x = position.second + dx[i];

			if (IsRange(y, x, y_size, x_size) && maze[y][x] == 1 && distance[y][x] == 0) {
				distance[y][x] = distance[position.first][position.second] + 1;
				q.push(make_pair(y, x));

				if (y == y_size-1 && x == x_size-1)
					return distance[y][x];
			}
		}

	}

	return distance[y_size-1][x_size-1];
}

bool IsRange(int y, int x, int y_size, int x_size) {
	return y >= 0 && y < y_size && x >= 0 && x < x_size;
}
