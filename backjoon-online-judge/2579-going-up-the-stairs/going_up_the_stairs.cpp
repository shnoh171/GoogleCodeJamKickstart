#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2579

int main()
{
	int n;
	cin >> n;
	int steps[n];
	for (int i = 0; i < n; ++i) cin >> steps[i];

	int d[n][2]; // second index: # of a continuous single step taken until n-1
	d[0][0] = steps[0]; d[0][1] = 0;
	if (n >= 2) {
		d[1][0] = steps[1]; d[1][1] = steps[0] + steps[1];
	}
	for (int i = 2; i < n; ++i) {
		d[i][0] = max(d[i-2][0], d[i-2][1]) + steps[i];
		d[i][1] = d[i-1][0] + steps[i];
	}

	cout << max(d[n-1][0], d[n-1][1]) << endl;
	
	return 0;
}
