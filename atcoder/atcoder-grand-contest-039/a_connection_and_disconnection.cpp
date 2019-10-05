#include <iostream>
using namespace std;

long long getNumberOfChange(long long size) {
	return size / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	long long k;

	cin >> s;
	cin >> k;

	bool single_pattern = true;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] != s[i+1]) {
			single_pattern = false;
			break;
		}
	}
	if (single_pattern) {
		cout << getNumberOfChange(s.size() * k) << endl;
		return 0;
	}

	int start = 0;
	int end = s.size() - 1;

	while (s[start] == s[0]) ++start;
	while (s[end] == s[s.size()-1]) --end;

	long long res = 0;
	char prev = s[start];
	int count = 1;
	for (int i = start + 1; i <= end; ++i) {

		if (s[i] == prev) {
			++count;
		} else {
			res += getNumberOfChange(count) * k;
			prev = s[i];
			count = 1;
		}
	}
	res += getNumberOfChange(count) * k;

	if ((k == 1) || (s[0] != s[s.size()-1])) {
		res += getNumberOfChange(start) * k;
		res += getNumberOfChange(s.size() - 1 - end) * k;
	} else {
		res += getNumberOfChange(start);
		res += getNumberOfChange(s.size() - 1 - end);
		res += getNumberOfChange(start + s.size() - 1 - end) * (k-1);
	}

	cout << res << endl;

	return 0;
}
