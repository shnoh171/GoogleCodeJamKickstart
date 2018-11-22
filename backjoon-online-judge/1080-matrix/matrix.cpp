#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1080

const int dy[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
const int dx[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int matrix[n][m];

	for (int i = 0 ; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			matrix[i][j] = s[j] - '0';
		}
	}

	for (int i = 0 ; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j] == s[j] - '0')
				matrix[i][j] = 0;
			else
				matrix[i][j] = 1;
		}
	}

	if (n <= 2 || m <= 2) {
		for (int i = 0 ; i < n; ++i) {
			for (int j = 0 ; j < m; ++j) {
				if (matrix[i][j] == 1) {
					cout << "-1\n";
					return 0;
				}
			}
		}
		cout << "0\n";
		return 0;
	}

	int count = 0;
	for (int i = 0; i < n-2; ++i) {
		for (int j = 0; j < m-2; ++j) {
			if (matrix[i][j] == 1) {
				++count;
				for (int k = 0; k < 9; ++k) {
					matrix[i+dy[k]][j+dx[k]] = 1 - matrix[i+dy[k]][j+dx[k]];
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		if (matrix[n-2][i] == 1 || matrix[n-1][i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (matrix[i][m-2] == 1 || matrix[i][m-1] == 1) {
			cout << "-1\n";
			return 0;
		}
	}

	cout << count << "\n";

	return 0;
}
