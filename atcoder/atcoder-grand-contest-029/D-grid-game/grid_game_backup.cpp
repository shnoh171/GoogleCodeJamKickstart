#include <iostream>
#include <set>
using namespace std;

bool is_obs[200001][200001] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w, n;
	cin >> h >> w >> n;

	//bool is_obs[h+1][w+1] = {};
	set<int> c_members[w+1];

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		is_obs[x][y] = true;
		c_members[y].insert(x);
	}
	

	int visited[w+1];
	int x = 1, y = 1;
	while (x <= h && y <= w) {
		if (is_obs[++x][y]) break;
		if (!is_obs[x][y+1]) {
			visited[y] = x;
			++y;
		}
	}

	int res = x-1;

	for (int i = 1; i < y-1; ++i) {
		if (!c_members[i].empty())
			res = min(res, *c_members[i].upper_bound(visited[i]));
	}

	cout << res << "\n";

	return 0;
}
