#include <iostream>
#include <vector>
using namespace std;

int GetNumberOfCases(int n);
int GetNumberOfCasesSub(int y, vector<vector<bool>> &board);
bool IsValid(int y, int x, vector<vector<bool>> &board);
bool IsRange(int y, int x, int size) { return y >= 0 && y < size && x >= 0 && x < size; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << GetNumberOfCases(n) << "\n";

	return 0;
}

int GetNumberOfCases(int n)
{
	vector<vector<bool>> board(n, vector<bool>(n, false));
	return GetNumberOfCasesSub(0, board);
}

int GetNumberOfCasesSub(int y, vector<vector<bool>> &board)
{
	if (y >= board.size()) return 1;

	int ret = 0;
	for (int x = 0; x < board.size(); ++x) {
		if (IsValid(y, x, board)) {
			board[y][x] = true;
			ret += GetNumberOfCasesSub(y+1, board);
			board[y][x] = false;
		}
	}
	return ret;
}

bool IsValid(int y, int x, vector<vector<bool>> &board)
{
	//   1 2 3 4 5
	// 1 x   x   x
	// 2   x x x
	// 3     o
	int dx = 0;
	while (--y >= 0) {
		++dx;
		if (board[y][x]) return false;
		if (IsRange(y, x-dx, board.size()) && board[y][x-dx]) return false;
		if (IsRange(y, x+dx, board.size()) && board[y][x+dx]) return false;
	}
	return true;
}