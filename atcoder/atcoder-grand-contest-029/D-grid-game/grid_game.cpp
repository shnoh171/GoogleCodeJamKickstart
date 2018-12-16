#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w, n;
	cin >> h >> w >> n;

	set<pair<int, int> > is_obs;
	set<int> c_members[w+1];

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		is_obs.insert(make_pair(x, y));
		c_members[y].insert(x);
	}
	

	int visited[w+1];
	int x = 1, y = 1;
	while (true) {
		// Go up
		if (x == h || is_obs.find(make_pair(x+1, y)) != is_obs.end()) {
			visited[y] = x;
			break;
		} else {
			++x;
		}
		
		// Go right
		if (y != w && is_obs.find(make_pair(x, y+1)) == is_obs.end()) {
			visited[y] = x;
			++y;
		}
	}

	int res = x;
	for (int i = 1; i < y-1; ++i) {
		if (!c_members[i].empty()) {
			set<int>::iterator it = c_members[i].upper_bound(visited[i]);
			if (it != c_members[i].end())
				res = min(res, *it-1);
		}
	}

	cout << res << "\n";

	return 0;
}
