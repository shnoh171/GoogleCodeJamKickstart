#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void find(int start, int end, vector<pair<int, int> > counts);
bool check(int num, vector<pair<int, int> > counts);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int s[n];
	for (int i = 0; i < n; ++i) cin >> s[i];

	unordered_map<int, int> hashmap;
	for (int i = 0; i < n; ++i)	++hashmap[s[i]];

	vector<pair<int, int> > counts;

	for (unordered_map<int, int>::const_iterator iter = hashmap.begin();
		 iter != hashmap.end(); ++iter) {
		pair<int, int> instance;
		instance.first = iter->second;
		instance.second = iter->first;
		counts.push_back(instance);
	}

	sort(counts.begin(), counts.end());
	reverse(counts.begin(), counts.end());

	for (int i = 0; i < counts.size(); ++i)
		cout << counts[i].first << " " << counts[i].second << endl;

	find(1, n/k, counts);

	return 0;
}

void find(int start, int end, vector<pair<int, int> > counts) {
	if (start < end)
		f
}

bool check(int num, vector<pair<int, int> > counts) {
	int sum = 0;
	for (int i = 0; i < counts.size(); ++i) {
		sum += counts.first;
	}
}
