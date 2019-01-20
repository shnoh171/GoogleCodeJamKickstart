#include <iostream>
using namespace std;

const long long mod = 1000000007;
int CalcNum(int l, int r, int remainder);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, r;
	cin >> n >> l >> r;

	int num[3];
	for (int i = 0; i < 3; ++i)
		num[i] = CalcNum(l, r, i);

	long long d[3][n+1];
	d[0][1] = num[0];
	d[1][1] = num[1];
	d[2][1] = num[2];

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {
			d[j][i] = (d[j][i-1] * num[0]) % mod;
			d[j][i] = (d[j][i] + d[(j+1)%3][i-1] * num[2]) % mod;
			d[j][i] = (d[j][i] + d[(j+2)%3][i-1] * num[1]) % mod;
		}
	}

	cout << d[0][n] << "\n";

	return 0;
}

int CalcNum(int l, int r, int remainder)
{
	l += (3 - remainder);
	r += (3 - remainder);
	int res = r/3 - l/3;
	if (l%3 == 0) ++res;
	return res;
}