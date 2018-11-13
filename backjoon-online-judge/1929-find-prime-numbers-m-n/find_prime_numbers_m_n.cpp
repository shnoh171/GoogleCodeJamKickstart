#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/1929
// Sieve of Eratosthenes
// Why timeout? I don't understand...

int main()
{
	ios_base::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;

	bool primes[n+1];
	fill_n(primes, n+1, true);

	primes[0] = false; primes[1] = false;

	for (int i = 2; i*i <= n; ++i) {
		if (primes[i] == true) {
			for (int j = 2*i; j <= n; j += i) {
				primes[j] = false;
			}
		}
	}

	for (int i = m; i <= n; ++i)
		if (primes[i] == true)
			cout << i << endl;

	return 0;
}
