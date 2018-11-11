#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; ++i) cin >> A[i];

	int d[n][2]; // 0: increasing, 1: decreasing
	d[0][0] = 1; d[0][1] = 1;
	for (int i = 1; i < n; ++i) {
		d[i][0] = 1; d[i][1] = 1;
		for (int j = i-1; j >= 0; --j) {
			if (A[j] < A[i]) {
				d[i][0] = max(d[i][0], d[j][0] + 1);
			}
			if (A[j] > A[i]) {
				d[i][1] = max(d[i][1], d[j][0] + 1);
				d[i][1] = max(d[i][1], d[j][1] + 1);
			}
		}
	}

	int res = *max_element(&d[0][0], &d[0][0]+ 2*n);
	cout << res << endl;

	return 0;
}
