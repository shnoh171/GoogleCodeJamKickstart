#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/9466

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		int students[n+1];
		for (int j = 1; j < n+1; ++j) cin >> students[j];

		int numberings[n+1] = {};
		const int done = n+1;
		int count = 0;

		for (int j = 1; j < n+1; ++j) {
			if (numberings[j] == done) continue;

			int k = j;
			int order = 1;

			while (numberings[k] == 0) {
				numberings[k] = order++;
				k = students[k];
			}

			if (numberings[k] == done) count += order-1;
			else count += numberings[k]-1;

			k = j;
			while (numberings[k] != done) {
				numberings[k] = done;
				k = students[k];
			}
		}
		cout << count << "\n";
	}

	return 0;
}
