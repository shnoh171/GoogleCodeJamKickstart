#include <iostream>
#include <vector>
using namespace std;

const int dx[3] = { -1, 0, 1 };
const int dy[3] = { 1, 1, 1 };

bool IsRange(int y, int x, int n) { return y >= 0 && y < n && x >= 0 && x < n; }
int CalNumOfQ(int y, vector<vector<bool> > board);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<bool> > board(n, vector<bool>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			board[i][j] = true;

	cout << CalNumOfQ(0, board) << "\n";

	return 0;
}

int CalNumOfQ(int y, vector<vector<bool> > board)
{
	int n = board.size();
	if (y == n) return 1;

	int res = 0;

	for (int x = 0; x < n; ++x) {
		if (board[y][x]) {
			vector<vector<bool> > next = board;
			for (int i = 0; i < 3; ++i) {
				int next_y = y, next_x = x;
				while (IsRange(next_y, next_x, n)) {
					next[next_y][next_x] = false;
					next_y += dy[i];
					next_x += dx[i];
				}
			}
			/*
			cout << "(y, x) = (" << y << ", " << x << ")\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << next[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			*/
			res += CalNumOfQ(y+1, next);
		}
	}

	return res;
}
