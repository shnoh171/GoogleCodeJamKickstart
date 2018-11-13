#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1978
// check Sieve of Eratosthenes

int main()
{
	int n, cnt = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) cin >> nums[i];
	
	for (int i = 0; i < n; ++i) {
		if (nums[i] < 2) continue;

		int j;
		for (j = 2; j*j <= nums[i]; ++j) {
			if (nums[i] % j == 0) break;
		}
		if (j*j > nums[i]) ++cnt;
	}

	cout << cnt << endl;

	return 0;
}
