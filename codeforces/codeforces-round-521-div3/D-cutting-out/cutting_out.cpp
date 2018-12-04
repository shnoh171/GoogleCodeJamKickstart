#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void find(int lower, int upper, int k, vector<pair<int, int> > counts);
bool check(int num, int k, vector<pair<int, int> > counts);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	map<int, int> hashmap;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		++hashmap[val];
	}

	vector<pair<int, int> > counts;

	for (map<int, int>::const_iterator iter = hashmap.begin();
		 iter != hashmap.end(); ++iter) {
		pair<int, int> instance;
		instance.first = iter->second;
		instance.second = iter->first;
		counts.push_back(instance);
	}

	sort(counts.begin(), counts.end());
	reverse(counts.begin(), counts.end());

	find(1, n/k+1, k, counts);
	cout << "\n";

	return 0;
}

void find(int lower, int upper, int k, vector<pair<int, int> > counts) {
	if (upper == lower) {
		int i = 0;
		while (k > 0) {
			int repeat = counts[i].first/upper;

			if (k - repeat < 0) 
				for (int j = 0; j < k; ++j) 
					cout << counts[i].second << " ";
			else
				for (int j = 0; j < repeat; ++j) 
					cout << counts[i].second << " ";

			k -= repeat;
			++i;
		}
		return;
	}

	int mid = (upper + lower) / 2 + 1;

	if (check(mid, k, counts))
		find(mid, upper, k, counts);
	else
		find(lower, mid-1, k, counts);
}

bool check(int num, int k, vector<pair<int, int> > counts) {
	int cnt = 0;
	int i = 0;
	while (k > 0) {
		if (i >= counts.size()) break;
		if (counts[i].first < num) break;

		int repeat = counts[i].first/num;
		k -= repeat;
		++i;
	}
	if (k <= 0) return true;
	else return false;
}

