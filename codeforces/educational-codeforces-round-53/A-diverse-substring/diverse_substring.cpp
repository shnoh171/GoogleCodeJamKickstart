#include <iostream>
#include <string>
using namespace std;

// http://codeforces.com/contest/1073/problem/A

int main()
{
	int n;
	string s;
	cin >> n >> s;

	if (n == 1) {
		cout << "NO" << endl;
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		if (s[i] != s[0]) {
			cout << "YES" << endl << s.substr(i-1, 2) << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
