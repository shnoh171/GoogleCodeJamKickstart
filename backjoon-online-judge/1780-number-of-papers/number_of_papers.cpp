#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1780

struct count {
	int minus_one;
	int zero;
	int plus_one;
};

const int dy[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
const int dx[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

count GetNumOfPapers(int y, int x, int size, vector<vector<int> >& paper);

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int> > paper(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			cin >> paper[i][j];

	count res = GetNumOfPapers(0, 0, n, paper);
	cout << res.minus_one << "\n" << res.zero << "\n" << res.plus_one << "\n";

	return 0;
}

count GetNumOfPapers(int y, int x, int size, vector<vector<int> >& paper) {
	count ret = {};

	if (size == 1) {
		if (paper[y][x] == -1) ret.minus_one = 1;
		else if (paper[y][x] == 0) ret.zero = 1;
		else if (paper[y][x] == 1) ret.plus_one = 1;

		return ret;
	}

	count subpaper[9];
	int subsize = size / 3;

	for (int i = 0; i < 9; ++i)
		subpaper[i] = GetNumOfPapers(y + dy[i]*subsize, x + dx[i]*subsize, subsize, paper);
	
	for (int i = 0; i < 9; ++i) {
		if (subpaper[i].minus_one != 1 || subpaper[i].zero != 0 || subpaper[i].plus_one != 0)
			break;
		if (i == 8) {
			ret.minus_one = 1;
			return ret;
		}
	}

	for (int i = 0; i < 9; ++i) {
		if (subpaper[i].minus_one != 0 || subpaper[i].zero != 1 || subpaper[i].plus_one != 0)
			break;
		if (i == 8) {
			ret.zero= 1;
			return ret;
		}
	}

	for (int i = 0; i < 9; ++i) {
		if (subpaper[i].minus_one != 0 || subpaper[i].zero != 0 || subpaper[i].plus_one != 1)
			break;
		if (i == 8) {
			ret.plus_one= 1;
			return ret;
		}
	}

	for (int i = 0; i < 9; ++i) {
		ret.minus_one += subpaper[i].minus_one;
		ret.zero += subpaper[i].zero;
		ret.plus_one += subpaper[i].plus_one;
	}

	return ret;
}
