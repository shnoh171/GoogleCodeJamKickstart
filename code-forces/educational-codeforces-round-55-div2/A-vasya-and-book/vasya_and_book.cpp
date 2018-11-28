#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, x, y, d;
		cin >> n >> x >> y >> d;

		if (abs(x-y) % d == 0) {
			cout << abs(x-y) / d << '\n';
		} else if (abs(y-1) % d == 0 && abs(n-y) % d != 0) {
			int move = abs(x-1) / d + 1 + abs(y-1) / d;
			cout << move << '\n';
		} else if (abs(y-1) % d != 0 && abs(n-y) % d == 0) {
			int move = abs(n-x) / d + 1 + abs(n-y) / d;
			cout << move << '\n';
		} else if (abs(y-1) % d == 0 && abs(n-y) % d == 0) {
			int move1 = abs(x-1) / d + 1 + abs(y-1) / d;
			int move2 = abs(n-x) / d + 1 + abs(n-y) / d;
			cout << min(move1, move2) << '\n';
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}
