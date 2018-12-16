#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	set<string> record;

	for (int i = 0; i < n; ++i) {
		string name, command;
		cin >> name >> command;
		if (command == "enter") {
			record.insert(name);
		} else if (command == "leave") {
			record.erase(name);
		}
	}

	for (set<string>::const_reverse_iterator it = record.rbegin();
	     it != record.rend(); ++it) {
		cout << *it << "\n";
	}

	return 0;
}
