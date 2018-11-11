#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1699

int main()
{
	int n;
	cin >> n;

	int d[n+1];
	d[1] = 1;
	int max_root = 1;

	for (int i = 2; i <= n; i++) {
		if ((max_root+1) * (max_root+1) == i) {
			d[i] = 1;
			++max_root;
		} else {
			d[i] = d[max_root*max_root] + d[i-max_root*max_root];
			for (int j = max_root - 1; j >= 1; --j) {
				d[i] = min(d[i], d[j*j] + d[i-j*j]);
			}
		}
	}

	cout << d[n] << endl;

	return 0;
}
