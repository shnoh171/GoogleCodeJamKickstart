#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][31][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, w;
	cin >> t >> w;
	int seq[t+1];
	for (int i = 1; i <= t; ++i) {
		int id;
		cin >> id;
		seq[i] = --id; // {1, 2} -> {0, 1}
	}

	d[0][0][0] = 0;
	d[0][0][1] = -1;
	for (int i = 1; i <= t; ++i) {
		if (seq[i] == 0) d[i][0][0] = d[i-1][0][0] + 1;
		else d[i][0][0] = d[i-1][0][0];
		d[i][0][1] = -1;		
	}

	d[1][1][0] = -1;
	d[1][1][1] = (seq[1] == 1);

	for (int j = 2; j <= w; ++j) {
		d[1][j][0] = d[1][j][1] = -1;
	}

	for (int i = 2; i <= t; ++i) {
		for (int j = 1; j <= w; ++j) {
			for (int k = 0; k <= 1; ++k) {
				int cand1 = d[i-1][j-1][(k+1)%2];
				int cand2 = d[i-1][j][k];

				if (cand1 < 0 && cand2 < 0) {
					d[i][j][k] = -1;
				} else if (cand1 < 0) {
					d[i][j][k] = cand2 + (k == seq[i]);
				} else if (cand2 < 0) {
					d[i][j][k] = cand1 + (k == seq[i]);
				} else {
					d[i][j][k] = max(cand1, cand2) + (k == seq[i]);
				}
			}
		}
	}

	int res = 0;
	for (int j = 0; j <= w; ++j)
		for (int k = 0; k <= 1; ++k)
			res = max(res, d[t][j][k]);
	
	if (res < 0) cout << "0\n";
	else cout << res << "\n";

	return 0;
}
