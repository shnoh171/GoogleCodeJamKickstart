#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/1912

int main()
{
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; ++i) cin >> A[i];

	int d[n];
	d[0] = A[0];

	for (int i = 1; i < n; ++i) {
		if (d[i-1] < 0) {
			d[i] = A[i];
		} else {
			d[i] = d[i-1] + A[i];
		}
	}

	cout << *max_element(d, d+n) << endl;

	return 0;
}
