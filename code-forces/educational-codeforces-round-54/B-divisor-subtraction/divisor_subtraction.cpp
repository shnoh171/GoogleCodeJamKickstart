#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long origin_n = n;

	long long cnt = 0;

	if (n % 2 == 1) {
		long long div = 3;
		
		while (div * div <= n) {
			if (n % div == 0) {
				n-= div;
				++cnt;
				break;
			}
			++div;
		}

		if (div * div > origin_n) {
			cout << 1 << endl;
			return 0;
		}
	}

	cout << n/2 + cnt << endl;

	return 0;
}
