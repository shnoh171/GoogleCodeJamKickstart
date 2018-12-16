#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<string> never_heard;
	set<string> never_heard_and_seen;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		never_heard.insert(name);
	}
	
	for (int i = 0; i < m; ++i) {
		string name;
		cin >> name;
		if (never_heard.find(name) != never_heard.end()) {
			never_heard_and_seen.insert(name);
		}
	}

	cout << never_heard_and_seen.size() << "\n";
	for (auto it = never_heard_and_seen.begin(); it != never_heard_and_seen.end(); ++it)
		cout << *it << "\n";

	return 0;
}
