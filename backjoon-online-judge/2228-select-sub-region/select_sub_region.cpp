#include <iostream>
#include <algorithm>
using namespace std;

const int ninf = -987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int seq[n+1];
	for (int i = 1; i <= n; ++i) cin >> seq[i];

	int d1[m+1][n+1], d2[m+1][n+1];

	d1[0][0] = d2[0][0] = ninf;
	int max_element = seq[1];
	for (int i = 1; i <= n; ++i) {
		d1[1][i] = seq[i];
		d2[1][i] = max(max_element, seq[i-1]);
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j < 2*i - 1) {
				d1[i][j] = ninf;
				d2[i][j] = ninf;
			} else if (j == 2*i - 1) {
				d1[i][j] = 0;
				for (int k = 1; k <= j; ++k)
					if (k % 2 == 1) d1[i][j] += seq[k];
				d2[i][j] = ninf;
			} else if (j == 2*i) {
				d1[i][j] = max(d1[i][j-1] + seq[j], d2[i-1][j-1] + seq[j]);
				d2[i][j] = d1[i][j-1];
			} else if (j > 2*i) {
				d1[i][j] = max(d1[i][j-1] + seq[j], d2[i-1][j-1] + seq[j]);
				d2[i][j] = max(d1[i][j-1], d2[i][j-1]);
			}
		}
	}

	cout << max(d1[m][n], d2[m][n]) << "\n";

	return 0;
}
