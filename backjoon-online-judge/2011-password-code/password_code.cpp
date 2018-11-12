#include <iostream>
#include <cstdlib>
using namespace std;

// https://www.acmicpc.net/problem/2011

const int mod = 1000000;

int to_int(char c)
{
	return c - '0';
}

int main()
{
	string s;
	cin >> s;

	int d[s.size()];

	if (s[0] == '0') {
		cout << 0 << endl;
		return 0;
	} else {
		d[0] = 1;
	}
	if (s.size() == 1) {
		cout << d[0] << endl;
		return 0;
	}

	if (s[1] == '0' && to_int(s[0]) >= 3) {
		cout << 0 << endl;
		return 0;
	} else if (s[1] == '0' && to_int(s[0]) <= 2) {
		d[1] = 1;
	} else {
		int val = to_int(s[0]) * 10 + to_int(s[1]);
		if (val <= 26) d[1] = 2;
		else d[1] = 1;
	}

	for (int i = 2; i <= s.size() - 1; ++i) {
		if (s[i] == '0') {
			if (s[i-1] != '1' && s[i-1] != '2') {
				cout << 0 << endl;
				return 0;
			}
			d[i] = d[i-2] % mod;
		} else if (to_int(s[i]) >= 1 && to_int(s[i]) <= 6) {
			if (s[i-1] == '1' || s[i-1] == '2')
				d[i] = (d[i-1] + d[i-2]) % mod;
			else
				d[i] = d[i-1] % mod;
		} else if (to_int(s[i]) >= 7 && to_int(s[i]) <= 9) {
			if (s[i-1] == '1')
				d[i] = (d[i-1] + d[i-2]) % mod;
			else
				d[i] = d[i-1] % mod;
		}
	}

	cout << d[s.size()-1] << endl;

	return 0;
}
