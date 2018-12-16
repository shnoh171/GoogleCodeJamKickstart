#include <iostream>
#include <string>
using namespace std;

const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, -1, 1, 0 };

char board[20][20];
int r, c;
bool visit[26] = {};

bool IsRange(int y, int x) {return y >= 0 && y < r && x >= 0 && x < c; }
int Solve(int y, int x);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j) {
			board[i][j] = s[j];
		}
	}

	int res = Solve(0, 0);
	cout << res << "\n";

	return 0;
}

int Solve(int y, int x) {
	char c = board[y][x];
	//cout << y << " " << x << " " << c << endl;

	if (!IsRange(y, x)) return 0;
	if (visit[c-'A']) return 0;

	visit[c-'A'] = true;
	int res = 0;

	for (int i = 0; i < 4; ++i) {
		int next_y = y + dy[i];
		int next_x = x + dx[i];
		res = max(res, 1 + Solve(next_y, next_x));
	}

	visit[c-'A'] = false;

	return res;
}
