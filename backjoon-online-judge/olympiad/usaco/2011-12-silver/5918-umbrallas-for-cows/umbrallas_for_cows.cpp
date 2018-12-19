#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/5918
// Incomplete

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

	int d[n];
	d[0] = c[1];
	for (int i = 1; i < n; ++i) {
		d[i] = c[x[i]-x[0]+ 1];
		for (int j = 0; j < i; ++j) {
			d[i] = min(d[i], d[j] + c[x[i]-x[j+1]+1]);
		}
	}

	cout << d[n-1] << "\n";

	return 0;
}
