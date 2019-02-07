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

	int a[n], b[n], c[n], d[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	int front[n*n], back[n*n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			front[n*j+i] = a[i] + b[j];
			back[n*j+i] = c[i] + d[j];
		}
	}

	sort(front, front+n*n);
	sort(back, back+n*n);

	long long count = 0;
	int fidx = 0;
	int bidx = n*n-1;

	while (fidx < n*n && bidx >= 0) {
		int res = front[fidx] + back[bidx];
		if (res == 0) {
			int fprev = front[fidx];
			int bprev = back[bidx];
			int fcnt = 0, bcnt = 0;
			while (fidx < n*n && front[fidx] == fprev) {
				++fidx;
				++fcnt;
			}
			while (bidx >= 0 && back[bidx] == bprev) {
				--bidx;
				++bcnt;
			}
			count += (long long)fcnt * bcnt;
		} else if (res > 0) {
			--bidx;
		} else if (res < 0) {
			++fidx;
		}
	}

	cout << count << "\n";

	return 0;
}
