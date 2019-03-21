#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Too slow

vector<int> switches[10] =
{
	{ 0, 1, 2 },
	{ 3, 7, 9, 11 },
	{ 4, 10, 14, 15},
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15 },
	{ 3, 14, 15 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

bool IsAnswer(const vector<int> &clocks);
void GetSmallestNumber(vector<int> &clocks);
bool CheckNumber(vector<int> &clocks, int index, int remainings, int length);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
		vector<int> clocks;
		for (int i = 0; i < 16; ++i) {
			int clk;
			cin >> clk;
			clocks.push_back(clk % 12);
		}

		GetSmallestNumber(clocks);
	}

	return 0;
}

bool IsAnswer(const vector<int> &clocks)
{
	for (int i = 0; i < clocks.size(); ++i) {
		if (clocks[i] != 0) return false;
	}
	return true;
}
void GetSmallestNumber(vector<int> &clocks)
{
	for (int length = 1; length <= 30; ++length) {
		if (CheckNumber(clocks, 0, length, length)) return;
	}
	cout << "-1\n";
	return;
}
bool CheckNumber(vector<int> &clocks, int index, int remainings, int length)
{
	if (index >= 10) return false;

	if (remainings == 0 && IsAnswer(clocks)) {
		cout << length << "\n";
		return true;
	}

	if (remainings < 0 || (remainings == 0 && !IsAnswer(clocks))) {
		return false;
	}

	//for (int i = 0; i < 12; ++i) cout << clocks[i] << " ";
	//cout << endl;

	bool ret = false;

	for (int i = 0; i < 4; ++i) {
		for (int k = 0; k < i; ++k) {
			for (int j = 0; j < switches[index].size(); ++j) {
				clocks[switches[index][j]] = (clocks[switches[index][j]] + 3) % 12;
			}
		}
		ret = ret || CheckNumber(clocks, index + 1, remainings - i, length);
		for (int k = 0; k < i; ++k) {
			for (int j = 0; j < switches[index].size(); ++j) {
				clocks[switches[index][j]] = (clocks[switches[index][j]] + 9) % 12;
			}
		}
	}

	return ret;
}