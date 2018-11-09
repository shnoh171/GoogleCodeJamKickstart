#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2156

int main()
{
	int n;
	cin >> n;

	int wines[n];
	for (int i = 0; i < n; i++) cin >> wines[i];

	int d[n][3];
	d[0][0] = 0; d[0][1] = wines[0]; d[0][2] = 0;
	for (int i = 1; i < n; i++) {
		d[i][0] = max(d[i-1][0], max(d[i-1][1], d[i-1][2]));
		d[i][1] = d[i-1][0] + wines[i];
		d[i][2] = d[i-1][1] + wines[i];
	}

	cout << max(d[n-1][0], max(d[n-1][1], d[n-1][2])) << endl;

	return 0;
}
