#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int p[n];
	for (int i = 0; i < n; ++i) cin >> p[i];

	int max_val = *max_element(p, p+n);
	int ret = accumulate(p, p+n, 0) - max_val/2;

	cout << ret << "\n";

	return 0;
}
