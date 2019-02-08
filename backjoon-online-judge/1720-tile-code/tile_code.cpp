#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	long long d[n+1];
	memset(d, 0, (n+1)*sizeof(long long));
	
	d[0] = 1; d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i-2] * 2 + d[i-1];
	}

	int symmetric;
	if (n % 2)
		symmetric = d[n/2];
	else
		symmetric = d[n/2] + d[n/2-1] * 2;
	int asymmetric = d[n] - symmetric;

	cout << symmetric + asymmetric / 2 << "\n";

	return 0;
}
