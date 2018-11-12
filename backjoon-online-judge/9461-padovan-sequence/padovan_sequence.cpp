#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/9461

int main()
{
	int t;
	cin >> t;
	int n[t+1];
	for (int i = 1; i <= t; ++i) cin >> n[i];

	int size = *max_element(n+1, n+t+1);
	long d[size];
	if (size >= 1) d[1] = 1;
	if (size >= 2) d[2] = 1;
	if (size >= 3) d[3] = 1;
	if (size >= 4) d[4] = 2;
	if (size >= 5) d[5] = 2;

	for (int i = 6; i <= size; ++i)
		d[i] = d[i-1] + d[i-5];

	for (int i = 1; i <= t; ++i)
		cout << d[n[i]] << endl;

	return 0;
}
