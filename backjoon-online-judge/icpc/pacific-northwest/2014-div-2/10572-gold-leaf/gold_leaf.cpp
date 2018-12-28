//#define PRINT_ALL
//#define FILE_IO

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct fold {
	int r1;
	int c1;
	int r2;
	int c2;

	fold() {}
	fold(int ir1, int ic1, int ir2, int ic2) {
		r1 = ir1; c1 = ic1; r2 = ir2; c2 = ic2;
	}
};

fold MinFold(fold a, fold b);
bool IsRange(int r, int c, int n, int m);

fold CheckHorizontalFold(int r, const vector<vector<char>> &photo);
fold CheckVerticalFold(int c, const vector<vector<char>> &photo);
fold CheckDiagonalFold(int r, int c, char type, const vector<vector<char>> &photo);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef FILE_IO
	ifstream fin("GoldLeaf.in");
	ofstream fout("GoldLeaf.out");
#endif

	int num_of_cases;
#ifdef FILE_IO
	fin >> num_of_cases;
#else
	cin >> num_of_cases;
#endif
	

	while (num_of_cases--) {
		int n, m;
#ifdef FILE_IO
		fin >> n >> m;
#else
		cin >> n >> m;
#endif
		vector<vector<char>> photo(n + 1, vector<char>(m + 1));

		for (int i = 1; i < n + 1; ++i) {
			string s;
#ifdef FILE_IO
			fin >> s;
#else
			cin >> s;
#endif
			for (int j = 1; j < m + 1; ++j)
				photo[i][j] = s[j-1];
		}

		fold res_h;
		fold res_v;
		fold res_d1;
		fold res_d2;

		for (int i = 1; i < n; ++i) {
			res_h = CheckHorizontalFold(i, photo);
			if (res_h.r1 != 0 || res_h.c1 != 0 ||
			    res_h.r2 != 0 || res_h.c2 != 0)
				break;				
		}
#ifdef PRINT_ALL
		cout << res_h.r1 << " " << res_h.c1 << " " << res_h.r2 << " " << res_h.c2 << endl;
#endif

		for (int i = 1; i < m; ++i) {
			res_v = CheckVerticalFold(i, photo);
			if (res_v.r1 != 0 || res_v.c1 != 0 ||
				res_v.r2 != 0 || res_v.c2 != 0)
				break;
		}

#ifdef PRINT_ALL
		cout << res_v.r1 << " " << res_v.c1 << " " << res_v.r2 << " " << res_v.c2 << endl;
#endif

		for (int i = 2; i <= n + m - 2; ++i) {
			res_d1 = CheckDiagonalFold(min(i, n), max(1, i - n + 1), '/', photo);
			if (res_d1.r1 != 0 || res_d1.c1 != 0 ||
				res_d1.r2 != 0 || res_d1.c2 != 0)
				break;
		}

#ifdef PRINT_ALL
		cout << res_d1.r1 << " " << res_d1.c1 << " " << res_d1.r2 << " " << res_d1.c2 << endl;
#endif

		for (int i = 2; i <= n + m - 2; ++i) {
			res_d2 = CheckDiagonalFold(min(n + m - i, n), min(i, m), '\\', photo);
			if (res_d2.r1 != 0 || res_d2.c1 != 0 ||
				res_d2.r2 != 0 || res_d2.c2 != 0)
				break;
		}

#ifdef PRINT_ALL
		cout << res_d2.r1 << " " << res_d2.c1 << " " << res_d2.r2 << " " << res_d2.c2 << endl;
#endif

#ifndef PRINT_ALL
		fold res = MinFold(MinFold(MinFold(res_h, res_v), res_d1), res_d2);
#ifdef FILE_IO
		fout << res.r1 << ' ' << res.c1 << ' ' << res.r2 << ' ' << res.c2 << "\n";
		fout.flush();
#endif
#ifndef FILE_IO
		cout << res.r1 << ' ' << res.c1 << ' ' << res.r2 << ' ' << res.c2 << "\n";
#endif
#endif		
	}

	return 0;
}

fold MinFold(fold a, fold b)
{
	if (!a.r1 && !a.c1 && !a.r2 && !a.c2) return b;
	if (!b.r1 && !b.c1 && !b.r2 && !b.c2) return a;
	if (a.r1 < b.r1) return a;
	if (a.r1 > b.r1) return b;
	if (a.c1 < b.c1) return a;
	if (a.c1 > b.c1) return b;
	if (a.r2 < b.r2) return a;
	if (a.r2 > b.r2) return b;
	if (a.c2 < b.c2) return a;
	if (a.c2 > b.c2) return b;
	
	return a;
}

bool IsRange(int r, int c, int n, int m)
{
	return r >= 1 && r <= n && c >= 1 && c <= m;
}

fold CheckHorizontalFold(int r, const vector<vector<char>> &photo)
{
	int n = photo.size() - 1;
	int m = photo[0].size() - 1;

	if (r * 2 <= n) {
		for (int i = 1; i <= r; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (photo[i][j] == photo[2 * r - i + 1][j])
					return fold(0, 0, 0, 0);
			}
		}
		for (int i = r * 2 + 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (photo[i][j] == '.')
					return fold(0, 0, 0, 0);
			}
		}
		return fold(r, 1, r, m);
	}
	else {
		for (int i = r + 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (photo[i][j] == photo[2 * r - i + 1][j])
					return fold(0, 0, 0, 0);
			}
		}
		for (int i = 1; i <= 2 * r - n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (photo[i][j] == '.')
					return fold(0, 0, 0, 0);
			}
		}
		return fold(r, 1, r, m);
	}
}

fold CheckVerticalFold(int c, const vector<vector<char>> &photo)
{
	int n = photo.size() - 1;
	int m = photo[0].size() - 1;

	if (c * 2 <= m) {
		for (int i = 1; i <= c; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (photo[j][i] == photo[j][2 * c - i + 1])
					return fold(0, 0, 0, 0);
			}
		}
		for (int i = c * 2 + 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (photo[j][i] == '.')
					return fold(0, 0, 0, 0);
			}
		}
		return fold(1, c, n, c);
	}
	else {
		for (int i = c + 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (photo[j][i] == photo[j][2 * c - i + 1])
					return fold(0, 0, 0, 0);
			}
		}
		for (int i = 1; i <= 2 * c - m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (photo[j][i] == '.')
					return fold(0, 0, 0, 0);
			}
		}
		return fold(1, c, n, c);
	}
}

fold CheckDiagonalFold(int r, int c, char type, const vector<vector<char>> &photo)
{
	int n = photo.size() - 1;
	int m = photo[0].size() - 1;

	if (type == '/') {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int next_i = r + c - j;
				int next_j = r + c - i;
				if (r - i != j - c && IsRange(next_i, next_j, n, m)) {
					if (photo[i][j] == photo[next_i][next_j])
						return fold(0, 0, 0, 0);
				}
				else {
					if (photo[i][j] == '.')
						return fold(0, 0, 0, 0);
				}
			}
		}
		
		if (c + r - 1 <= m)
			return fold(r, c, 1, c + r - 1);
		else
			return fold(r, c, r - m + c, m);
	}
	else {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				int next_i = r - c + j;
				int next_j = c - r + i;
				if (r - i != c - j && IsRange(next_i, next_j, n, m)) {
					if (photo[i][j] == photo[next_i][next_j])
						return fold(0, 0, 0, 0);
				}
				else {
					if (photo[i][j] == '.')
						return fold(0, 0, 0, 0);
				}
			}
		}

		if (r - c + 1 >= 1)
			return fold(r - c + 1, 1, r, c);
		else
			return fold(1, c - r + 1, r, c);
	}
}
