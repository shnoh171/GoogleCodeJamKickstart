#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/2110

bool InstallRouters(int interval, int number, int houses[], int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	int houses[n];
	for (int i = 0; i < n; ++i) cin >> houses[i];
	sort(houses, houses+n);

	int left = 1;
	int right = 1000000000;
	int ans = 1; 

	while (left <= right) {
		int mid = (left + right) / 2;
		if (InstallRouters(mid, c, houses, n)) {
			ans = max(ans, mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}

bool InstallRouters(int interval, int number, int houses[], int n)
{
	int count = 1;
	int prev_house = houses[0];
	for (int i = 1; i < n; ++i) {
		if (houses[i] - prev_house >= interval) {
			++count;
			prev_house = houses[i];
		}
		if (count >= number) {
			return true;
		}
	}
	return false;
}
