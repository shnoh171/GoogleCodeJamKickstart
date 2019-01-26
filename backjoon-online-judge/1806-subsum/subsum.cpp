#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 987654321;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;
	int seq[n];
	for (int i = 0; i < n; ++i) cin >> seq[i];

	int head = 0, tail = 0;
	int sum = seq[0];
	int res = inf;

	while (tail < n) {
		if (sum >= s) {
			res = min(res, tail - head + 1);
			sum -= seq[head++];
		} else {
			++tail;
			if (tail < n) sum += seq[tail];
		}
	}

	cout << (res < inf ? res : 0) << "\n";

	return 0;
}
