#define WAIT
#include <iostream>
#include <queue>
using namespace std;

// incomplete

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int length[100001] = {};
	queue<int> q;

	length[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		int next = curr * 2;
		if (next <= 100000 && length[next] == 0) {
			length[next] = length[curr] + 1;
			q.push(next);
		}

		if ((curr-1) % 3 == 0) {
			int next = (curr-1) / 3;
			if (next <= 100000 && length[next] == 0) {
				length[next] = length[curr] + 1;
				q.push(next);
			}
		}
	}

	int input;
	cin >> input;

	cout << length[input] << "\n";

#ifdef WAIT
	cout << flush;
	system("pause");
#endif

	return 0;
}
