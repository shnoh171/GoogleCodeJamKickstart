#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int counts[200001];
	cin >> n >> k;
	for (int i = 0; i < 200001; ++i) counts[i] = -1;

	queue<int> q;
	counts[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (curr == k) {
			cout << counts[curr] << "\n";
			return 0;
		}

		if (curr > 0 && counts[curr-1] == -1) {
			counts[curr-1] = counts[curr] + 1;
			//cout << curr-1 << " " << counts[curr-1] << endl;
			q.push(curr-1);
		}

		if (curr < 200000 && counts[curr+1] == -1) {
			counts[curr+1] = counts[curr] + 1;
			q.push(curr+1);
		}

		if (curr*2 <= 200000 && counts[curr*2] == -1) {
			counts[curr*2] = counts[curr] + 1;
			q.push(curr*2);
		}
	}

	return 0;
}
