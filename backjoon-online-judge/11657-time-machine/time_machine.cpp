#include <iostream>
#include <algorithm>
using namespace std;

const int max_val = 987654321;

struct route {
	int start;
	int end;
	int time;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int dist[n+1];
	dist[1] = 0;
	for (int i = 2; i < n+1; ++i) dist[i] = max_val;

	route routes[m];
	for (int i = 0; i < m; ++i)
		cin >> routes[i].start >> routes[i].end >> routes[i].time;
	
	for (int i = 0; i < n-1; ++i) {
		for (int j = 0; j < m; ++j) {
			int from = routes[j].start;
			int to = routes[j].end;
			int time = routes[j].time;
			if (dist[from] < max_val)
				dist[to] = min(dist[to], dist[from] + time);
		}
	}

	for (int j = 0; j < m; ++j) {
		int from = routes[j].start;
		int to = routes[j].end;
		int time = routes[j].time;
		if (dist[from] < max_val && dist[to] > dist[from] + time) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 2; i < n+1; ++i)
		cout << (dist[i] == max_val ? -1 : dist[i]) << "\n";

	return 0;
}
