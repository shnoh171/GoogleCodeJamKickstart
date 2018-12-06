#include <iostream>
#include <algorithm>
using namespace std;

const int max_val = 10 * 10 * 1000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int seq[n];
	for (int i = 0; i < n; ++i) seq[i] = i;

	int w[n][n];
	for (int i = 0 ; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];

	int res = max_val;
	do {
		bool flag = false;
		int sum = 0;
		for (int i = 0; i < n-1; ++i) {
			int weight = w[seq[i]][seq[i+1]];
			if (weight == 0) flag = true;
			sum += weight;
		}
		if (w[seq[n-1]][seq[0]] == 0) flag = true;
		sum += w[seq[n-1]][seq[0]];
		if (!flag) res = min(res, sum);
	} while (next_permutation(seq, seq+n));

	cout << res << "\n";

	return 0;
}
