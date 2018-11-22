#include <iostream>
using namespace std;

// https://algospot.com/judge/problem/read/BOGGLE

struct Delta {
	int dy;
	int dx;
};

const Delta deltas[8] = {
	{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,1}, {1,-1}, {1,0}, {1,1}
};

bool hasWord(int y, int x, string word, char board[5][5]);
bool isRange(int y, int x) { return  x < 0 || x >= 5 || y < 0 || y >= 5; }

int main()
{
	ios_base::sync_with_stdio(false);

	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		char board[5][5];
		for (int j = 0; j < 5; ++j) {
			string s;
			cin >> s;
			for (int k = 0; k < 5; ++k)
				board[j][k] = s[k];
		}

		int n;
		cin >> n;

		for (int j = 0; j < n; ++j) {
			string word;
			bool exist = false;
			cin >> word;

			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 5; ++l) {
					exist = hasWord(k, l, word, board);
					if (exist) break;
				}
				if (exist) break;
			}

			cout << word << " ";
			cout << ((exist) ? "YES" : "NO") << "\n";
		}
	}

	return 0;
}

bool hasWord(int y, int x, string word, char board[5][5]) {
	if (isRange(y, x)) return false;
	if (word.empty()) return true;
	if (word[0] != board[y][x]) return false;

	bool ret = false;

	for (int i = 0; i < 8; ++i) {
		int dy = deltas[i].dy;
		int dx = deltas[i].dx;

		if (hasWord(y+dy, x+dx, word.substr(1), board))
			return true;
	}

	return false;
}
