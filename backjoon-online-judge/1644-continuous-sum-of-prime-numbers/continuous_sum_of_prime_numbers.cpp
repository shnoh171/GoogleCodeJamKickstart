#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	bool is_prime[n+1];
	vector<int> prime;
	memset(is_prime, true, (n+1)*sizeof(bool));

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j = 2*i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}

	if (prime.empty()) {
		cout << "0\n";
		return 0;
	}

	int head = 0, tail = 0;
	int sum = prime[0];
	int count = 0;

	while (tail < prime.size()) {
		if (sum == n) {
			++count;
			sum -= prime[head++];
		} else if (sum < n) {
			++tail;
			if (tail < prime.size())
				sum += prime[tail];
		} else if (sum > n) {
			sum -= prime[head++];
		}
	}

	cout << count << "\n";

	return 0;
}
