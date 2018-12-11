#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int D(int number);
int S(int number);
int L(int number);
int R(int number);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;

		bool visit[10000];
		memset(visit, false, sizeof(visit));

		pair<int, int> info[10000];

		queue<int> q;
		visit[a] = true;
		q.push(a);

		while (!q.empty()) {
			int number = q.front();
			q.pop();

			if (number == b) {
				string res;
				while (number != a) {
					res += info[number].second;
					number = info[number].first;
				}
				reverse(res.begin(), res.end());
				cout << res << "\n";
				break;
			}

			int candidates[4];
			candidates[0] = D(number);
			candidates[1] = S(number);
			candidates[2] = L(number);
			candidates[3] = R(number);

			for (int j = 0; j < 4; ++j) {
				if (visit[candidates[j]] == false) {
					visit[candidates[j]] = true;
					info[candidates[j]].first = number;
					if (j == 0) info[candidates[j]].second = 'D';
					else if (j == 1) info[candidates[j]].second = 'S';
					else if (j == 2) info[candidates[j]].second = 'L';
					else if (j == 3) info[candidates[j]].second = 'R';

					q.push(candidates[j]);
				}
			}
		}
	}

	return 0;
}

int D(int number)
{
	return (2 * number) % 10000;
}

int S(int number)
{
	if (number == 0) return 9999;
	else return number - 1;
}

int L(int number)
{
	return (10 * number) % 10000 + number / 1000;
}

int R(int number)
{
	return number / 10 + (number % 10) * 1000;
}

