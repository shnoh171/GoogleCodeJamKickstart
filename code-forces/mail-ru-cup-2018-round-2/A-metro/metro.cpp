#include <iostream>
using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;

	int stations[n+1][2];
	for (int i = 1; i <= n; ++i) cin >> stations[i][0];
	for (int i = 1; i <= n; ++i) cin >> stations[i][1];

	if (stations[1][0] == 0) {
		cout << "NO" << endl;
		return 0;
	}

	if (stations[s][0] == 1) {
		cout << "YES" << endl;
		return 0;
	}

	int turnaround = n;
	while (turnaround > 0) {
		if (stations[turnaround][0] == 1 && stations[turnaround][1] == 1)
			break;
		--turnaround;
	}

	if (s < turnaround && stations[s][1] == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

