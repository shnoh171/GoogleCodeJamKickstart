#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1463

int main()
{
	int N;
	cin >> N;
	vector<int> dp(N + 1);

	for (int i = 1; i <= N; ++i) {
		if (i == 1) {
			dp[i] = 0;
		} else {
			int val = dp[i-1];
			if (i % 2 == 0) val = min(val, dp[i/2]);
			if (i % 3 == 0) val = min(val, dp[i/3]);
			dp[i] = val + 1;
		}
	}

	cout << dp[N] << endl;

	return 0;
}
