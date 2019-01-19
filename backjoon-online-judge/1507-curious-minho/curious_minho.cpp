#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

const int inf = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int dist[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> dist[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dist[i][j] != dist[j][i]) {
				cout << "-1\n";
				return 0;
			}
			if (i == j && dist[i][j] != 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}

	int check[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) check[i][j] = 0;
			else check[i][j] = inf;
		}
	}

	vector<tuple<int, int, int>> cand;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			cand.push_back(make_tuple(dist[i][j], i, j));
		}
	}
	sort(cand.begin(), cand.end());

	int res = 0;
	for (auto x : cand) {
		int d = get<0>(x);
		int n1 = get<1>(x);
		int n2 = get<2>(x);

		if (check[n1][n2] < d) {
			cout << "-1\n";
			return 0;
		}

		if (check[n1][n2] > d) {
			check[n1][n2] = d;
			check[n2][n1] = d;
			res += d;
			for (int i = 0; i < n; ++i) {
				for (int j = i+1; j < n; ++j) {
					check[i][j] = min(check[i][j], check[i][n1] + check[n2][j] + d);
					check[i][j] = min(check[i][j], check[i][n2] + check[n1][j] + d);
					check[j][i] = min(check[j][i], check[j][n1] + check[n2][i] + d);
					check[j][i] = min(check[j][i], check[j][n2] + check[n1][i] + d);
				}
			}
		}
	}

	cout << res << "\n";

	return 0;
}
