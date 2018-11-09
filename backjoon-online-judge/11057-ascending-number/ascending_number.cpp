#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/11057

int main()
{
	const int mod = 10007;
	int n;
	cin >> n;
	int d[n+1][10];

	for (int i = 0; i < 10; ++i) d[1][i] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			d[i][j] = 0;
			for (int k = j; k >= 0; --k) {
				d[i][j] = (d[i][j] + d[i-1][k]) % mod;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 10; ++i)
		ret = (ret + d[n][i]) % mod;

	cout << ret << endl;

	return 0;
}
