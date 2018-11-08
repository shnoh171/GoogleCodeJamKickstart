#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/11052

int main()
{
	int N;
	cin >> N;

	int P[N+1];
	for (int i = 1; i <= N; ++i) cin >> P[i];

	int d[N+1] = { 0, };

	d[1] = P[1];
	for (int i = 2; i <= N; ++i) {
		d[i] = P[i];
		for (int j = 1; j <= i/2; ++j) 
			d[i] = max(d[i], d[j] + d[i-j]);
	}

	cout << d[N] << endl;

	return 0;
}
