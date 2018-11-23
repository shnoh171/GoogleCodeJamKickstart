#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/4963

const int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void DigUpIsland(int y, int x, vector<vector<int> >& ground);
bool IsRange(int y, int x, int height, int weight);

int main()
{
	ios_base::sync_with_stdio(false);

	while (1) {
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		vector<vector<int> > ground(h, vector<int>(w));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> ground[i][j];
			}
		}

		int count = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (ground[i][j] == 1) {
					++count;
					DigUpIsland(i, j, ground);
				}
			}
		}

		cout << count << "\n";
	}

	return 0;
}

void DigUpIsland(int y, int x, vector<vector<int> >& ground) 
{
	queue<pair<int, int> > q;
	ground[y][x] = 0;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		pair<int, int> position = q.front();
		q.pop();

		for (int i = 0; i < 8; ++i) {
			int next_y = position.first + dy[i];
			int next_x = position.second + dx[i];

			if (!IsRange(next_y, next_x, ground.size(), ground[0].size()))
				continue;

			if (ground[next_y][next_x] == 1) {
				ground[next_y][next_x] = 0;
				q.push(make_pair(next_y, next_x));
			}
		}
	}
}

bool IsRange(int y, int x, int height, int weight)
{
	return y >= 0 && y < height && x >= 0 && x < weight;
}
