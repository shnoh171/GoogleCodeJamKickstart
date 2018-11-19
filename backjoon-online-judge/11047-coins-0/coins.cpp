#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; ++i) cin >> coins[i];

	reverse(coins.begin(), coins.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += k / coins[i];
		k -= (k / coins[i]) * coins[i];
	}

	cout << cnt << "\n";

	return 0;
}
