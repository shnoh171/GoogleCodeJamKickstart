#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1201
// Incomplete

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	if (n < m + k - 1) {
		cout << "-1\n";
		return 0;
	}

	cout << 1;
	bool is_increasing = true;
	int count_inc = 1;
	int count_dec = 0;

	for (int i = 2; i < n; ++i) {
		if (is_increasing) {
			cout << " " << i;
			if (++count_inc 

		} else {

		}
	}
	
	cout << "\n";

	return 0;
}
