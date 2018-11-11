#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2133

int main()
{
	int n;
	cin >> n;

	int d[n+1];
	d[0] = 1; d[1] = 0;

	for (int i = 2; i <= n; ++i) {
		d[i] = d[i-2] * 3;
		for (int j = i-4; j >= 0; j -= 2) {
			d[i] += d[j] * 2;
		}
	}

	cout << d[n] << endl;

	return 0;
}
