#include <iostream>
using namespace std;

// https://algospot.com/judge/problem/read/BOGGLE

// Improvement point 1: Separate the list of relative coordinates
// into separate variables.

// Improvement point 2: Use more functions for modularization.

// Improvement point 3: Setting base case when word.size() == 1 will
// reduce the number of recursive calls.


bool hasWord(int y, int x, string word, char board[5][5]);

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
	if (word.empty()) return true;

	if (word[0] == board[y][x]) {
		bool ret = false;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i == 0 && j == 0) continue;
				if (y+i < 0 || y+i >= 5 || x+j < 0 || x+j >= 5) continue;
				ret = hasWord(y+i, x+j, word.substr(1, word.size()-1), board);
				if (ret) break;
			}
			if (ret) break;
		}
		return ret;
	} else {
		return false;
	}
}
