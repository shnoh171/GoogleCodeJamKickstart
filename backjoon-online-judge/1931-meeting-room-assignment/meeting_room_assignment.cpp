#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/1931

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	pair<int, int> meetings[n];
	for (int i = 0; i < n; ++i)
		cin >> meetings[i].first >> meetings[i].second;

	sort(meetings, meetings+n);

	int criterion = 0;
	int count = 1;
	for (int i = 1; i < n; ++i) {
		if (meetings[criterion].second <= meetings[i].first) {
			criterion = i;
			++count;
		} else if (meetings[criterion].second > meetings[i].second) {
			criterion = i;
		}
	}

	cout << count << "\n";

	return 0;
}
