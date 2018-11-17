#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int,int> > a(n);
	for (int i = 0; i < n; ++i) {
		pair<int, int> instance;
		cin >> (instance.first);
		instance.second = i+1;
		a[i] = instance;
	}

	sort(a.begin(), a.end());

	int sum = 0;
	vector<int> good;

	for (int i = 0; i < n; ++i) sum += (a[i].first);

	for (int i = 0; i < n-1; ++i) {
		if (sum - a[i].first - a[n-1].first == a[n-1].first) {
			good.push_back(a[i].second);
		}
	}
	if (sum - a[n-1].first - a[n-2].first == a[n-2].first) {
		good.push_back(a[n-1].second);
	}

	cout << good.size() << "\n";
	if (good.size() > 0) cout << good[0];
	for (int i = 1; i < good.size(); ++i)
		cout << " " << good[i];
	cout << "\n";

	return 0;
}
