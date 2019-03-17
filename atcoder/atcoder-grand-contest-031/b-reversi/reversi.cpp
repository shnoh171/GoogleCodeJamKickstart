#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mod = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];

	map<int, int> most_recent;
	vector<int> d(n);

	d[0] = 1;
	most_recent[c[0]] = 0;

	for (int i = 1; i < n; ++i) {
		if (most_recent.find(c[i]) != most_recent.end() && i - most_recent[c[i]] >= 2) {
			d[i] = (d[i-1] + d[most_recent[c[i]]]) % mod;
		} else {
			d[i] = d[i-1];
		}
		most_recent[c[i]] = i;
	}

	cout << d[n-1] << "\n";

	return 0;
}
