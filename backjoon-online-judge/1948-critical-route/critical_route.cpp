#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> city[n+1];
    int in_degree[n+1];
    memset(in_degree, 0, (n+1) * sizeof(int));

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        city[from].push_back(pair<int,int>(to, weight));
        ++in_degree[to];
    }

    int start, end;
    cin >> start >> end;

    int time[n+1];
    memset(time, 0, (n+1) * sizeof(int));

    vector<int> reconstruct[n+1];

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto x : city[curr]) {
            int next = x.first;
            int weight = x.second;

            if (time[next] < time[curr] + weight) {
                time[next] = time[curr] + weight;
                reconstruct[next] = vector<int>(1, curr);
            } else if (time[next] == time[curr] + weight) {
                reconstruct[next].push_back(curr);
            }

            if (!(--in_degree[next]))
                q.push(next);
        }
    }

    int count = 0;
    bool check[n+1];
    memset(check, false, (n+1) * sizeof(bool));

    q.push(end);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto next : reconstruct[curr]) {
            ++count;
            if (!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }

    cout << time[end] << "\n";
    cout << count << "\n";

	return 0;
}
