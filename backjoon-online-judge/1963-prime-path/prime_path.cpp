#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool is_prime[10000];
	for (int i = 0; i < 10000; ++i) is_prime[i] = true;
	is_prime[0] = false; is_prime[1] = false;

	for (int i = 2; i*i < 10000; ++i)
		if (is_prime[i])
			for (int j = 2*i; j < 10000; j += i)
				is_prime[j] = false;

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int counts[10000];
		for (int i = 0; i < 10000; ++i) counts[i] = -1;

		int from, to;
		cin >> from >> to;

		queue<int> q;
		counts[from] = 0;
		q.push(from);
		bool flag = false;

		while (!q.empty()) {
			int now = q.front();
			q.pop();

			if (now == to) {
				cout << counts[now] << "\n";
				flag = true;
				break;
			}

			for (int order = 1; order <= 1000; order *= 10) {
				int number = now - now % (order*10) + now % order; 
				for (int j = 0; j < 10; ++j) {
					int next = number + order*j;
					if (is_prime[next] && next >= 1000 && counts[next] == -1) {
						counts[next] = counts[now] + 1;
						q.push(next);
					}
				}
			}
		}

		if(!flag) cout << "Impossible\n";
	}


	return 0;
}
