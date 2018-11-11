#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/11055

int main()
{
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; ++i) cin >> A[i];

	int d[n];
	d[0] = A[0];
	for (int i = 0; i < n; ++i) {
		d[i] = A[i];
		for (int j = i-1; j >= 0; --j) {
			if (A[j] < A[i]) {
				d[i] = max(d[i], d[j] + A[i]);
			}
		}
	}

	cout << *max_element(d, d+n) << endl;

	return 0;
}
