#include <iostream>
#include <vector>
#include <string>
using namespace std;

pair<int, int> candidates[12][3] =
{
	{ make_pair(0, 0), make_pair(-1, 0), make_pair(-1, -1) },
	{ make_pair(0, 0), make_pair(-1, 0), make_pair(-1, 1) },
	{ make_pair(0, 0), make_pair(0, 1), make_pair(-1, 1) },
	{ make_pair(0, 0), make_pair(0, 1), make_pair(1, 1) },
	{ make_pair(0, 0), make_pair(1, 0), make_pair(1, -1) },
	{ make_pair(0, 0), make_pair(1, 0), make_pair(1, 1) },
	{ make_pair(0, 0), make_pair(0, -1), make_pair(-1, -1) },
	{ make_pair(0, 0), make_pair(0, -1), make_pair(1, -1) },
	{ make_pair(0, 0), make_pair(-1, 0), make_pair(0, 1) },
	{ make_pair(0, 0), make_pair(0, 1), make_pair(1, 0) },
	{ make_pair(0, 0), make_pair(1, 0), make_pair(0, -1) },
	{ make_pair(0, 0), make_pair(0, -1), make_pair(-1, 0) }
};

bool isRange(int y, int x, int h, int w) { return y >= 0 && x >= 0 && y < h && x < w; }
int getNumberOfCombinations(vector<vector<bool>> &board);
void solve();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) solve();

	return 0;
}

int getNumberOfCombinations(vector<vector<bool>> &board)
{
	int h = board.size();
	int w = board[0].size();

	int fy = 0, fx = 0;
	while (fy < h) {
		if (board[fy][fx]) break;
		if (++fx == w) {
			fx = 0;
			++fy;
		}	
	}
	if (fy == h) return 1;

	int ret = 0;
	for (int i = 0; i < 12; ++i) {
		int ny[3], nx[3];
		bool flag = true;
		for (int j = 0; j < 3; ++j) {
			ny[j] = fy + candidates[i][j].first;
			nx[j] = fx + candidates[i][j].second;
			
			if (!isRange(ny[j], nx[j], h, w) || !board[ny[j]][nx[j]]) {
				flag = false;
				break;
			}
		}
		
		if (flag) {
			for (int j = 0; j < 3; ++j) {
				board[ny[j]][nx[j]] = false;
			}
			ret += getNumberOfCombinations(board);
			for (int j = 0; j < 3; ++j) {
				board[ny[j]][nx[j]] = true;
			}
		}
	}
	return ret;
}

void solve()
{
	int h, w;
	cin >> h >> w;
	vector<vector<bool>> board(h, vector<bool>(w));

	for (int i = 0; i < h; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < w; ++j) {
			if (s[j] == '#') board[i][j] = false;
			else board[i][j] = true;
		}
	}

	cout << getNumberOfCombinations(board) << "\n";
}
