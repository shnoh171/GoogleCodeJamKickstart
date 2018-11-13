#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/11005

string base_conv(int n, int b);

int main()
{
	int n, b;
	cin >> n >> b;
	cout << base_conv(n, b) << endl;;

	return 0;
}

string base_conv(int n, int b) {
	string s;
	
	while (n > 0) {
		int r = n % b;
		if (r < 10) {
			s += to_string(r);
		} else {
			char digit = 'A' + r - 10;
			s.insert(s.end(), digit);
		}
		n = n / b;
	}
	reverse(s.begin(), s.end());

	return s;
}
