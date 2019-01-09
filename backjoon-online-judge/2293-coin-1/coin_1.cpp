#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

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

	int d[k+1];
	for (int i = 0; i < k+1; ++i)
		d[i] = (i % coin[0] == 0) ? 1 : 0;
	
	for (int i = 1; i < n; ++i) {
		for (int j = k; j >= 1; --j) {
			int curr = 0;
			int idx = j;
			while (idx >= 0) {
				curr += d[idx];
				idx -= coin[i];
			}
			d[j] = curr;
		}
	}
	
	cout << d[k] << "\n";
	
	return 0;
}
