#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) cin >> s[i];

	int res = 0;

	for (int i = 0; i < n; ++i) {
		vector<int> set_id(n, 0);
		bool failed = false;

		queue<int> q;
		q.push(i);
		set_id[i] = 1;
		int cres = 1;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int i = 0; i < n; ++i) {
				if (s[curr][i] == '1') {
					if (set_id[i] == 0) {
						set_id[i] = set_id[curr] + 1;
						cres = max(cres, set_id[i]);
						q.push(i);
					} else {
						for (int j = 0; j < n; ++j) {
							if (s[i][j] == '1') {
								if ((set_id[j] != 0) && (abs(set_id[i] - set_id[j]) != 1)) {
									failed = true;
									break;
								}
							}
						}
						if (failed) break;
					}
				}
			}
		}

		if (failed) continue;
		res = max(res, cres);
	}


	if (res == 0)
		cout << "-1\n";
	else
		cout << res << "\n";

	return 0;
}
