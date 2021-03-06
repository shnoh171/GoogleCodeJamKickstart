#include <iostream>
#include <set>
#include <vector>
using namespace std;

int board[9][9];

bool Solve(int idx);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
		}
	}

	Solve(0);

	return 0;
}

bool Solve(int idx)
{
	int y = idx / 9;
	int x = idx % 9;

	if (idx == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j];
				if (j != 8) cout << " ";
			}
			cout << "\n";
		}
		return true;
	}

	if (board[y][x] != 0) {
		bool ret = Solve(idx + 1);
		if (ret) return true;
		else return false;
	}

	//set<int> row, col, squ;
	int bitset = 0;

	for (int i = 0; i < 9; ++i) {
		int num = board[y][i];
		if (num != 0) {
			//row.insert(num);
			bitset |= 1 << num;
		}
	}

	for (int i = 0; i < 9; ++i) {
		int num = board[i][x];
		if (num != 0) {
			//col.insert(num);
			bitset |= 1 << num;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int num = board[y - y % 3 + i][x - x % 3 + j];
			if (num != 0) {
				bitset |= 1 << num;
			}
		}
	}

	vector<int> cands;
	for (int i = 1; i < 10; ++i)
		if (!(bitset & 1 << i))
			cands.push_back(i);

	for (int i = 0; i < cands.size(); ++i) {
		board[y][x] = cands[i];
		bool ret = Solve(idx + 1);
		if (ret) return true;
		board[y][x] = 0;
	}
	return false;
}