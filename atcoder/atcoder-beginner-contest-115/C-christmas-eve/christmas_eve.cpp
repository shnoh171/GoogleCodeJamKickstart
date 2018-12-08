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
	int h[n];
	for (int i = 0; i < n; ++i) cin >> h[i];
	sort(h, h+n);

	int res = *max_element(h, h+n);
	for (int i = 0; i <= n-k; ++i)
		res = min(res, h[i+k-1] - h[i]);

	cout << res << "\n";

	return 0;
}
