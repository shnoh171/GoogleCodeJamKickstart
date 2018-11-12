#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2225

const int mod = 1000000000;

int main()
{
	int n, k;
	cin >> n >> k;

	int d[n+1][k+1];

	for (int i = 1; i <= n; ++i) d[i][1] = 1;
	for (int i = 1; i <= k; ++i) d[1][i] = i;

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			d[i][j] = d[i-1][j] % mod;
			for (int l = j-1; l >=1; --l) {
				d[i][j] = (d[i][j] + d[i-1][l]) % mod;
			}
		}
	}

	cout << d[n][k] << endl;

	return 0;
}
