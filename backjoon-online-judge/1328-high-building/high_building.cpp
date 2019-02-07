#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000007;

int d[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, r;
	cin >> n >> l >> r;

	long long d[l+1][r+1];
	memset(d, 0, (l+1)*(r+1)*sizeof(long long));
	d[1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = l; j >= 1; --j) {
			for (int k = r; k >= 1; --k) {
				d[j][k] = ((i-2)*d[j][k] + d[j-1][k] + d[j][k-1]) % mod;
			}
		}
	}

	cout << d[l][r] << "\n";

	return 0;
}
