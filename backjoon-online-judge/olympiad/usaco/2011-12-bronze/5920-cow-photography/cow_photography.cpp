#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

bool IsRange(int i, int n) { return i >= 0 && i < n; }

/* Counter Example of the current approach
5
2 1 4 3 5
2 1 4 3 5
2 1 3 4 5
1 2 3 4 5
1 2 3 4 5
Answer: 2 1 3 4 5
 */

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int cows[5][n];

	for (int i = 0; i < 5; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> cows[i][j];

	int res[n];
	int prev_cow = 0, preprev_cow = 0;

	for (int i = 0; i < n; ++i) {
		map<int, int> counts;
		for (int j = i-1; j <= i+1; ++j) {
			if (!IsRange(j, n)) continue;

			for (int k = 0; k < 5; ++k) {
				int cow = cows[k][j];
				if (cow != prev_cow && cow != preprev_cow)
					++counts[cow];
			}

			stack<int> candidates;
			for (map<int, int>::const_iterator k = counts.begin(); k != counts.end(); ++k) 
				if (k->second >= 4) candidates.push(k->first);

			while (!candidates.empty()) {
				int candidate = candidates.top();
				candidates.pop();


			}




			bool flag = false;
			for (map<int, int>::const_iterator k = counts.begin(); k != counts.end(); ++k) {
				if (k->second >= 4) {
					res[i] = k->first;
					preprev_cow = prev_cow;
					prev_cow = k->first;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}	

	for (int i = 0; i < n; ++i )
		cout << res[i] << '\n';

	return 0;
}
