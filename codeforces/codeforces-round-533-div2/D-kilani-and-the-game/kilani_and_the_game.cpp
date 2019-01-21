/*
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

// Incomplete

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int cnt[10];

bool Round(int pid);
bool IsRange(int y, int x, int n, int m) { return y >= 0 && x >= 0 && y < n && x < m; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, p;
	cin >> n >> m >> p;
	char map[n][m];
	int dist[n][m];
	int s[p+1], cnt[p+1];
	memset(dist, 0, n*m*sizeof(int));
	memset(cnt, 0, (p+1)*sizeof(int));
	queue<pair<int, int>> q1, q2;
	vector<pair<int, int>> init[10];
	for (int i = 1; i <= p; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			map[i][j] = s[j];
			if (s[j] != '.' && s[j] != '#') {
				init[s[j]-'0'].push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 1; i < 10; ++i) {
		for (auto x : init[i]) {
			q2.push(x);
		}
	}

	while (!q2.empty() || !q1.empty()) {
		queue<pair<int, int>> &q = q1.empty() ? q2 : q1;
		
		if (!q1.empty() && !q2.empty()) {
			int p1 = map[q1.front().first][q1.front().second];
			int p2 = map[q2.front().first][q2.front().second];
			if (p1 == p2) q = q2;
			else q = q1;
		}
		
		pair<int, int> curr = q.front();
		int y = curr.first;
		int x = curr.second;
		int id = map[y][x] - '0';
		q.pop();

		++cnt[id];

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (IsRange(ny, nx, n, m) && map[ny][nx] == '.') {
				map[ny][nx] = id + '0';
				dist[ny][nx] = (dist[y][x] + 1) % s[id];
				if (dist[ny][nx])
					q1.push(make_pair(ny, nx));
				else
					q2.push(make_pair(ny, nx));
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << dist[i][j] << " ";
			}
			cout << "\n";
		}		
		cout << "\n";
	}

	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	for (int i = 1; i <= p; ++i)
		cout << cnt[i] << " ";
	cout << "\n";

	return 0;
}
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct node {
	int y;
	int x;
	int dist;
	node(int a, int b, int c) { y = a; x = b; dist = c; }
};

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

int n, m, p;
int s[10];
char map[1000][1000];
int dist[1000][1000];
queue<node> q[10];
int cnt[10];

bool Round(int pid);
bool IsRange(int y, int x) { return y >= 0 && x >= 0 && y < n && x < m; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; ++i) cin >> s[i];
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			map[i][j] = s[j];
			if (s[j] != '.' && s[j] != '#') {
				dist[i][j] = 0;
				int num = s[j] - '0';
				q[num].push(node(i, j, 0));
			}
		}
	}

	bool finish = false;
	while (!finish) {
		bool progress = false;
		for (int i = 1; i <= p; ++i) {
			bool tmp = Round(i);
			progress = tmp || progress;
		}
		finish = !progress;
	}

	for (int i = 1; i <= p; ++i)
		cout << cnt[i] << " ";
	cout << "\n";

	return 0;
}

bool Round(int pid)
{
	if (q[pid].empty()) return false;

	int count = 0;
	int dist_limit = q[pid].front().dist + s[pid];

	while (!q[pid].empty() && q[pid].front().dist < dist_limit) {
		node curr = q[pid].front();
		int y = curr.y;
		int x = curr.x;
		q[pid].pop();

		++count;
		++cnt[pid];
		
		for (int i = 0; i < 4; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];
			int next_dist = curr.dist + 1;

			if (IsRange(next_y, next_x)) {
				if (map[next_y][next_x] == '.') {
					map[next_y][next_x] = pid + '0';
					dist[next_y][next_x] = next_dist;
					q[pid].push(node(next_y, next_x, next_dist));
				}
			}
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	*/

	if (count == 0) return false;
	else return true;
}