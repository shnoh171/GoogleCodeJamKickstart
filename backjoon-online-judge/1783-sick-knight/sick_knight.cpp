#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1783

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	if (n == 1) {
		cout << "1\n";
	} else if (n == 2) {
		if (m >= 7) cout << "4\n";
		else if (m >= 5) cout << "3\n";
		else if (m >= 3) cout << "2\n";
		else cout << "1\n";
	} else {
		if (m == 1) cout << "1\n";
		else if (m == 2) cout << "2\n";
		else if (m == 3) cout << "3\n";
		else if (m == 4) cout << "4\n";
		else if (m == 5) cout << "4\n";
		else if (m <= 6) cout << "4\n";
		else cout << 4 + (m-6) << "\n";
	}

	return 0;
}
