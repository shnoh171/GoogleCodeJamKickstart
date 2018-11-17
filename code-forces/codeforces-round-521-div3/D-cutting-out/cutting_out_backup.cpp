#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int s[n];
	for (int i = 0; i < n; ++i) cin >> s[i];

	unordered_map<int, int> hashmap;
	for (int i = 0; i < n; ++i)	++hashmap[i];

	vector<pair<int, int> > counts;

	for (unordered_map<int, int>::const_iterator iter = hashmap.begin();
		 iter != hashmap.end(); ++iter) {
		pair<int, int> instance;
		instance.first = iter->second;
		instance.second = iter->first;
		counts.push_back(instance);
	}

	sort(counts.begin(), counts.end());

	cout << counts[0].first << " " << counts[0].second << endl;


	return 0;
}
