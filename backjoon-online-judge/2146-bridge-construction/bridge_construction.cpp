#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Can be improved by switching bool array check to int array numbering

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int ShortestBridgeLength(int y, int x, vector<vector<int> >& map, vector<vector<bool> >& check);
bool IsRange(int y, int x, int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int> > map(n, vector<int>(n));
	vector<vector<bool> > check(n, vector<bool>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			check[i][j] = false;
		}
	}

	int shortest_length = 2*n; // loose bound

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			shortest_length = min(shortest_length, ShortestBridgeLength(i, j, map, check));

	cout << shortest_length << "\n";

	return 0;
}

int ShortestBridgeLength(int y, int x, vector<vector<int> >& map, vector<vector<bool> >& check)
{
	int n = map.size();
	if (check[y][x] == true || map[y][x] == 0) return 2*n;

	queue<pair<int, int> > island;
	queue<pair<int, int> > sea;

	vector<vector<int> > dist(n, vector<int>(n));

	check[y][x] = true;
	island.push(make_pair(y, x));

	while (!island.empty()) {
		int curr_y = island.front().first;
		int curr_x = island.front().second;
		island.pop();

		for (int i = 0; i < 4; ++i) {
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];

			if (!IsRange(next_y, next_x, n)) continue;
			if (!check[next_y][next_x] && map[next_y][next_x] == 0) {
				check[next_y][next_x] = true;
				dist[next_y][next_x] = 1;
				sea.push(make_pair(next_y, next_x));
			}
			if (!check[next_y][next_x] && map[next_y][next_x] == 1) {
				check[next_y][next_x] = true;
				island.push(make_pair(next_y, next_x));
			}
		}
	}

	while (!sea.empty()) {
		int curr_y = sea.front().first;
		int curr_x = sea.front().second;
		sea.pop();

		for (int i = 0; i < 4; ++i) {
			int next_y = curr_y + dy[i];
			int next_x = curr_x + dx[i];

			if (!IsRange(next_y, next_x, n)) continue;
			if (map[next_y][next_x] == 0 && dist[next_y][next_x] == 0) {
				dist[next_y][next_x] = dist[curr_y][curr_x] + 1;
				sea.push(make_pair(next_y, next_x));
			}
			if (map[next_y][next_x] == 1 && !check[next_y][next_x]) {
				return dist[curr_y][curr_x];
			}
		}
	}

	return 2*n;
}

bool IsRange(int y, int x, int size)
{
	return y >= 0 && y < size && x >= 0 && x < size;
}
