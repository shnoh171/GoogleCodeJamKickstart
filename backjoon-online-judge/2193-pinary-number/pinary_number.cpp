#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long d[2][n+1];
	d[0][1] = 0; d[1][1] = 1;
	for (long long i = 2; i <= n; ++i) {
		d[0][i] = d[0][i-1] + d[1][i-1];
		d[1][i] = d[0][i-1];
	}

	cout << d[0][n] + d[1][n] << endl;

	return 0;
}

