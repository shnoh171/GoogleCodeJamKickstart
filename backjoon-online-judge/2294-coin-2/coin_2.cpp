#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	const int inf = 987654321;

	int coin[n];
	for (int i = 0; i < n; ++i) cin >> coin[i];
	sort(coin, coin+n);

	int d[k+1];
	d[0] = 0;
	for (int i = 1; i <= k; ++i) d[i] = inf;
	
	for (int i = coin[0]; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			int idx = i - coin[j];
			if (idx >= 0 && d[idx] < inf) {
				d[i] = min(d[i], d[idx] + 1);
			}
		}
	}

	cout << (d[k] < inf ? d[k] : -1) << "\n";

	return 0;
}