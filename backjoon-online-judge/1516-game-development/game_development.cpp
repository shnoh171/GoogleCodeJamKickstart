#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct job {
    int length;
    int start = 0;
    int end = 0;
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
        
        int val;
        cin >> val;
        while (val != -1) {
            graph[val].push_back(i);
            ++in_degree[i];
            cin >> val;
        }
    }

    queue<int> q;
    for (int i = 1; i < n+1; ++i)
        if (!in_degree[i])
            q.push(i);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        jobs[curr].end = jobs[curr].start + jobs[curr].length;

        for (int i = 0; i < graph[curr].size(); ++i) {
            int next = graph[curr][i];
            jobs[next].start = max(jobs[next].start, jobs[curr].end);
            if (!(--in_degree[next]))
                q.push(next);
        }
    }

    for (int i = 1; i < n+1; ++i)
        cout << jobs[i].end << "\n";

	return 0;
}
