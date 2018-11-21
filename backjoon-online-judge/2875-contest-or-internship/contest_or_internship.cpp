#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2875

int main()
{
	ios_base::sync_with_stdio(false);


	int n, m ,k;
	cin >> n >> m >> k;

	int team, remain;
	if (n > 2 * m) {
		team = m;
		remain = n - 2 * team;
	} else {
		team = n / 2;
		remain = (n - 2 * team) + (m - team);
	}

	if (k > remain) {
		k -= remain;
		team = !(k % 3) ? team - k / 3 : team - k / 3 - 1;
	}

	cout << team << "\n";

	return 0;
}
