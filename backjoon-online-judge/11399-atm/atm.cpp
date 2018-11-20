#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/11399

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int p[n];
	for (int i = 0; i < n; ++i) cin >> p[i];

	sort(p, p+n);

	int time = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		time += p[i];
		sum += time;
	}
	
	cout << sum << "\n";

	return 0;
}
