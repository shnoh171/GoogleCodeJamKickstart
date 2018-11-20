#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10569

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;

		vector<int> s(v);
		for (int j = 0; j < v; ++j) cin >> s[j];

		sort(s.begin(), s.end());

		int prev = 0;
		int max_num, max_cnt = 0;
		for (int j = 0; j < v-1; ++j) {
			if (s[j] != s[j+1]) {
				if (max_cnt < j - prev + 1) {
					max_cnt = j - prev + 1;
					max_num = s[j];
				}
				prev = j+1;
			}
		}

		if (max_cnt < v - prev) {
			max_cnt = v - prev;
			max_num = s[v-1];
		}

		cout << max_num << "\n";
	}

	return 0;
}
