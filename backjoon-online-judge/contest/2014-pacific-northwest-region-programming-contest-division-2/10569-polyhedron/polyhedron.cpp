#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/10569

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int v, e;
		cin >> v >> e;
		cout << 2 + e - v << "\n";
	}

	return 0;
}
