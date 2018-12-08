#include <iostream>
using namespace std;

long long GetNumberOfPatties(long long x, long long d_l[], long long d_p[], long long n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long x;
	cin >> n >> x;

	long long d_l[n+1];
	d_l[0] = 1;
	for (int i = 1; i < n+1; ++i)
		d_l[i] = 2*d_l[i-1] + 3;

	long long d_p[n+1];
	d_p[0] = 1;
	for (int i = 1; i < n+1; ++i)
		d_p[i] = 2*d_p[i-1] + 1;

	cout << GetNumberOfPatties(x, d_l, d_p, n) << "\n";
	
	return 0;
}

long long GetNumberOfPatties(long long x, long long d_l[], long long d_p[], long long n)
{
	if (n == 0) return 1;

	if (x == 1) {
		return 0;
	} else if (x <= 1 + d_l[n-1]) {
		return GetNumberOfPatties(x-1, d_l, d_p, n-1);
	} else if (x == 2 + d_l[n-1]) {
		return d_p[n-1] + 1;
	} else if (x <= 2 + 2*d_l[n-1]) {
		return d_p[n-1] + 1 + GetNumberOfPatties(x-d_l[n-1]-2, d_l, d_p, n-1);
	} else if (x == 3 + 2*d_l[n-1]) {
		return 2*d_p[n-1] + 1;
	}

	cout << "err" << endl;
}
