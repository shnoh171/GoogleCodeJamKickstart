#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct job {
    int length;
    int start = 0;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    vector<job> jobs(n+1);
    vector<vector<int>> graph(n+1);
    vector<int> in_degree(n+1);

    for (int i = 1; i < n+1; ++i) {
        cin >> jobs[i].length;
        int next_num;
        cin >> next_num;
        while (next_num--) {
            int val;
            cin >> val;
            graph[i].push_back(val);
            ++in_degree[val];
        }
    }

    queue<int> q;
    for (int i = 1; i < n+1; ++i)
        if (!in_degree[i])
            q.push(i);

    int res = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        int finish = jobs[curr].start + jobs[curr].length;
        res = max(res, finish);

        for (int i = 0; i < graph[curr].size(); ++i) {
            int next = graph[curr][i];
            jobs[next].start = max(jobs[next].start, finish);
            if (!(--in_degree[next]))
                q.push(next);
        }
    }

    cout << res << "\n";

	return 0;
}
