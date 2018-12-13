#include <iostream>
#include <set>
#include <queue>
using namespace std;

const int dir[6][2] = {
	{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}
}; // {from, to}

vector<int> Pour(int from, int to, vector<int> now, vector<int> full);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	vector<int> full(3);
	full[0] = a; full[1] = b; full[2] = c;

	set<int> res;
	set<vector<int> > visited;
	queue<vector<int> > q;

	vector<int> init(3);
	init[0] = 0; init[1] = 0; init[2] = c;
	visited.insert(init);
	q.push(init);
	res.insert(c);

	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();

		if (now[0] == 0) res.insert(now[2]);

		for (int i = 0; i < 6; ++i) {
			int from = dir[i][0];
			int to = dir[i][1];

			vector<int> next = Pour(from, to, now, full);
			if (visited.find(next) == visited.end()) {
				/*
				cout << from << " " << to << endl;
				cout << "now: ";
				for (int i = 0; i < now.size(); ++i) cout << now[i] << " ";
				cout << endl;
				cout << "next: ";
				for (int i = 0; i < next.size(); ++i) cout << next[i] << " ";
				cout << endl;
				*/
				visited.insert(next);
				q.push(next);
			}
		}
	}

	for (set<int>::const_iterator it = res.begin(); it != res.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";

	return 0;
}

vector<int> Pour(int from, int to, vector<int> now, vector<int> full) {
	vector<int> ret(3);
	ret[3-from-to] = now[3-from-to];
	
	if (now[from] + now[to] <= full[to]) {
		ret[from] = 0;
		ret[to] = now[from] + now[to];
	} else {
		ret[from] = now[from] + now[to] - full[to];
		ret[to] = full[to];
	}
	return ret;
}
