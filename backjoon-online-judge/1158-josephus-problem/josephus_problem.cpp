#include <iostream>
#include <queue>
using namespace std;

// https://www.acmicpc.net/problem/1158
// No need to use double queues!!

int main()
{
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	queue<int> first, second;

	for (int i = 1; i <= N; ++i)
		first.push(i);

	vector<int> res;
	int cnt = 0;
	bool first_to_second = true;

	while (!first.empty() || !second.empty()) {
		if (first_to_second) {
			if (first.empty()) {
				first_to_second = false;
				continue;
			} else {
				if ((cnt + 1) % M == 0)
					res.push_back(first.front());
				else 
					second.push(first.front());

				first.pop();
			}
		} else {
			if (second.empty()) {
				first_to_second = true;
				continue;
			} else {
				if ((cnt + 1) % M == 0)
					res.push_back(second.front());
				else 
					first.push(second.front());

				second.pop();
			}
		}

		++cnt;
	}

	cout << "<" << res[0];
	for (int i = 1; i < N; ++i)
		cout << ", " << res[i];
	cout << ">" << endl;

	return 0;
}

