#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/2667

int GetDivisionSize(int y, int x, vector<vector<int> >& check, int n);

bool IsRange(int y, int x, int n) { return y >= 0 && y < n && x >= 0 && x < n; }

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int> > check(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			check[i][j] = (s[j] == '1') ? false : true;
		}
	}

	vector<int> div_size;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int size = GetDivisionSize(i, j, check, n);
			if (size) div_size.push_back(size);
		}
	}

	sort(div_size.begin(), div_size.end());

	cout << div_size.size() << "\n";
	for (int i = 0; i < div_size.size(); ++i)
		cout << div_size[i] << "\n";

	return 0;
}

int GetDivisionSize(int y, int x, vector<vector<int> >& check, int n) {
	if (!IsRange(y, x, n)) return 0;
	if (check[y][x]) return 0;

	check[y][x] = true;
	
	int ret = 1;
	ret += GetDivisionSize(y-1, x, check, n);
	ret += GetDivisionSize(y+1, x, check, n);
	ret += GetDivisionSize(y, x-1, check, n);
	ret += GetDivisionSize(y, x+1, check, n);

	return ret;
}
