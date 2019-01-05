#include <iostream>
#include <vector>
using namespace std;

bool IsRange(int index, int size) { return index >= 1 && index <= size; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> seq(n+1);
	for (int i = 1; i < n+1; ++i)
		cin >> seq[i];

	vector<vector<bool>> d(n+1, vector<bool>(n+1));

	for (int i = 1; i < n+1; ++i) {
		d[i][i] = true;
		int delta = 1;
		while (IsRange(i-delta, n) && IsRange(i+delta, n)) {
			if (seq[i-delta] != seq[i+delta])
				break;
			else
				d[i-delta][i+delta] = true;
			++delta;
		}
	}

	for (int i = 1; i < n; ++i) {
		if (seq[i] == seq[i+1])
			d[i][i+1] = true;
		else
			continue;
		int delta = 1;
		while (IsRange(i-delta, n) && IsRange(i+1+delta, n)) {
			if (seq[i-delta] != seq[i+1+delta])
				break;
			else
				d[i-delta][i+1+delta] = true;
			++delta;
		}
	}

	int m;
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << d[s][e] << "\n";
	}

	return 0;
}
