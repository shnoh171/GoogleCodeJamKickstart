#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	sort(a, a+n);

	int res = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n-1; ++i) sum += abs(a[i]-a[i+1]);
		res = max(res, sum);
	} while (next_permutation(a, a+n));

	cout << res << "\n";

	return 0;
}
