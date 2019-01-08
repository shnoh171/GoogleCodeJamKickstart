#include <iostream>
#include <algorithm>
using namespace std;

// Incomplete

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int coin[n];
	for (int i = 0; i < n; ++i) {
		cin >> coin[i];
	}
	sort(coin, coin+n);

	if (k < coin[0]) {
		cout << 0 << "\n";
		return 0;
	}
	
	int d[k+1];
	for (int i = 0; i < coin[0]; ++i) {
		d[i] = 0;
	}
	d[coin[0]] = 1;

	for (int i = coin[0]+1; i <= k; ++i) {
		d[i] = n;
		for (int j = 0; j < n; ++j) {
			if (i - coin[j] >= 0) {
				d[i] = min(d[i], d[i - coin[j]] + 1);
			}
		}
	}

	cout << d[k] << "\n";	

	return 0;
}
