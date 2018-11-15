#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1676

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int ret = 0;

	for (int i = 5; i < n+1; ++i) {
		int tmp = i;
		while (tmp % 5 == 0) {
			++ret;
			tmp = tmp / 5;
		}
	}

	cout << ret << "\n";

	return 0;
}
