#include <iostream>
#include <algorithm>
using namespace std;

int d[1001][31][2];
int ComputeMax(int time, int change, int tree, int seq[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, w;
	cin >> t >> w;
	int seq[t];
	for (int i = 1; i <= t; ++i) {
		int id;
		cin >> id;
		seq[i] = --id; // {1, 2} -> {0, 1}
	}

	int res;
	if (t - 1 <= w) {
		res = t;
	} else {
		res = max(ComputeMax(t, w, 0, seq), ComputeMax(t, w, 1, seq));
	}

	cout << res << "\n";

	return 0;
}

int ComputeMax(int time, int change, int tree, int seq[])
{
	// handle base cases
	if (change == )

	if (d[time][change][tree] > 0)
		return d[time][change][tree];

	return d[time][change][tree] = max(
		d[time-1][change][tree] + 1,
		d[time-1][change-1][(tree+1)%2] + 1,
		d[time-1][change][(tree+1)%2]
	);
}
