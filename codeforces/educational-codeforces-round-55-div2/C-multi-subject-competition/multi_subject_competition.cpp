#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > subjects(m+1);
	for (int i = 0; i < n; ++i) {
		int s, r;
		cin >> s >> r;
		subjects[s].push_back(r);
	}
	for (int i = 1; i < m+1; ++i)
		sort(subjects[i].rbegin(), subjects[i].rend());
	
	map<int, int> candidates;
	for (int i = 1; i < m+1; ++i)
		candidates[i] = 0;

	int index = 0;
	int res = 0;
	while (!candidates.empty()) {
		int sum = 0;
		map<int, int>::iterator it = candidates.begin();
		while (it != candidates.end()) {
			int curr = it->first;
			if (subjects[curr].size() <= index) {
				++it;
				candidates.erase(curr);
			} else {
				candidates[curr] += subjects[curr][index];
				if (candidates[curr] < 0) {
					++it;
					candidates.erase(curr);
				} else {
					++it;
					sum += candidates[curr];
				}
			}
		}
		res = max(res, sum);
		++index;
	}

	cout << res << "\n";

	return 0;
}
