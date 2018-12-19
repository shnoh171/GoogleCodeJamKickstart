#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/5918

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int x[n], c[m+1];
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 1; i < m+1; ++i) cin >> c[i];
	sort(x, x+n);

	int min_c[m+1];
	min_c[m] = c[m];
	for (int i = m-1; i >= 0; --i) {
		min_c[i] = min(min_c[i+1], c[i]);
	}

	int d[n];
	d[0] = min_c[1];
	for (int i = 1; i < n; ++i) {
		d[i] = min_c[x[i]-x[0]+ 1];
		for (int j = 0; j < i; ++j) {
			d[i] = min(d[i], d[j] + min_c[x[i]-x[j+1]+1]);
		}
	}

	cout << d[n-1] << "\n";

	return 0;
}
