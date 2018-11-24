#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/11723

int main()
{
	ios_base::sync_with_stdio(false);

	int m;
	cin >> m;

	int set = 0;

	for (int i = 0; i < m; ++i){
		string command;
		int element;

		cin >> command;
		if (command != "all" && command != "empty")
			cin >> element;

		if (command == "add") {
			set = set | (1 << element);
		} else if (command == "remove") {
			set = set & ~(1 << element);
		} else if (command == "check") {
			if (set & (1 << element)) cout << "1\n";
			else cout << "0\n";
		} else if (command == "toggle") {
			set = set ^ (1 << element);
		} else if (command == "all") {
			set = (1 << 21) - 1;
		} else if (command == "empty") {
			set = 0;
		}
	}

	return 0;
}
