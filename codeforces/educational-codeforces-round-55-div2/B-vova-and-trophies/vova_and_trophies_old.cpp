#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;

	int start_of_gold = 0;
	while (s[start_of_gold] == 'S') ++start_of_gold;

	if (start_of_gold >= n) {
		cout << "0\n";
		return 0;
	} else if (start_of_gold == n-1) {
		cout << "1\n";
		return 0;
	}

	vector<int> golds, silvers;
	bool gold_turn = true;
	int gold_count = 1, silver_count = 0;

	for (int i = start_of_gold + 1; i < n; ++i) {
		if (gold_turn) {
			if (s[i] == 'G') {
				++gold_count;
			} else {
				golds.push_back(gold_count);
				gold_count = 0;
				silver_count = 1;
				gold_turn = false;
			}
		} else {
			if (s[i] == 'S') {
				++silver_count;
			} else {
				silvers.push_back(silver_count);
				silver_count = 0;
				gold_count = 1;
				gold_turn = true;
			}
		}
	}

	if (gold_count != 0) golds.push_back(gold_count);
	if (silver_count != 0) silvers.push_back(silver_count);
	if (golds.size() != silvers.size()) silvers.push_back(0);

	/*
	for (int i = 0; i < golds.size(); ++i) cout << golds[i] << ' ';
	cout << '\n';
	for (int i = 0; i < silvers.size(); ++i) cout << silvers[i] << ' ';
	cout << '\n';
	*/

	if (golds.size() == 0) {
		cout << "0\n";
	} else if (golds.size() == 1) {
		cout << golds[0] << '\n';
	} else if (golds.size() == 2) {
		if (silvers[0] == 1)  {
			cout << golds[0] + golds[1] << '\n';
		} else {
			cout << max(golds[0], golds[1]) + 1 << '\n';
		}
	} else {
		int max_beauty = 0;
		
		for (int i = 0; i < golds.size() - 1; ++i) {
			if (silvers[i] == 1) {
				max_beauty = max(golds[i] + golds[i+1] + 1, max_beauty);
			} else {
				max_beauty = max(golds[i] + 1, max_beauty);
			}
		}

		max_beauty = max(golds[golds.size()-1] + 1, max_beauty);

		cout << max_beauty << '\n';
	}

	return 0;
}
