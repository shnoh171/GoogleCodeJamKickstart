#include <iostream>
using namespace std;

int main()
{
	int  n, m, l;
	cin >> n >> m >> l;

	int a[n+1];
	for (int i = 1; i <= n; ++i) cin >> a[i];

	int cnt = 0;
	if (a[1] > l) ++cnt;
	for (int j = 2; j <= n; ++j) {
		if (a[j-1] <= l && a[j] > l) ++cnt;
	}

	for (int i = 0; i < m; ++i) {
		int cmd;
		cin >> cmd;

		if (cmd == 0) {
			cout << cnt << endl;
		} else if (cmd == 1) {
			int p, d;
			cin >> p >> d;

			int prev = a[p];
			a[p] += d;

			if (a[p] > l) a[p] = l + 1;

			if (prev <= l && a[p] > l) {
				if (n == 1) {
					++cnt;
				} else if (p == 1) {
					if (a[p+1] <= l) ++cnt;
				} else if (p == n) {
					if (a[p-1] <= l) ++cnt;
				} else {
					if (a[p-1] > l && a[p+1] > l) --cnt;
					else if (a[p-1] <= l && a[p+1] <= l) ++cnt;
				}
			}
		}
	}

	return 0;
}
