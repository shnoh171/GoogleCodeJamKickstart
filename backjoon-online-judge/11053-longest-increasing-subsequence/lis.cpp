#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int A[n+1];
	for (int i = 1; i <= n; ++i) cin >> A[i];

	int d[n+1];
	d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = 1;
		for (int j = i-1; j >= 1; --j) {
			if (A[j] < A[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int res = 1;
	for (int i = 1; i <=n; ++i) res = max(res, d[i]);
	cout << res << endl;

	return 0;
}
