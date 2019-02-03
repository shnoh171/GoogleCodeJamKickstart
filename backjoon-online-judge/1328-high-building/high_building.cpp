#include <iostream>
using namespace std;

// Incomplete

const int mod = 1000000007;

int d[101][101];
int See(int length, int observe);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, r;
	cin >> n >> l >> r;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			d[i][j] = -1;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res = (res + See(i-1, l) + 1) % mod;
		res = (res + See(n-i, r) + 1) % mod;
	}
	
	cout << res << "\n";

	return 0;
}

int See(int length, int observe) {
	if (length < observe) return 0;
	if (length == 0) return 0;
	if (length == 1 && observe == 1) return 1;
	if (d[length][observe] >= 0) return d[length][observe];

	int ret = 0;
	for (int i = 1; i <= length; ++i) {
		d[i-1][observe] = See(i-1, observe);
		ret = (ret + d[i-1][observe] + 1) % mod;
	}

	return ret;
}