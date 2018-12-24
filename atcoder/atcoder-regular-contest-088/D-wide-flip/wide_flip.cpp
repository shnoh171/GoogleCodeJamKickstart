#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	string r;
	for (int i = 0; i < s.size() - 1; ++i)
		if (s[i] == s[i + 1])
			r += "0";
		else
			r += "1";

	int res = s.size();
	for (int i = 0; i < r.size(); ++i) {
		if (r[i] == '1') {
			int distance = max(i + 1, (int)r.size() - i);
			res = min(res, distance);
		}
	}

	cout << res << "\n";

	return 0;
}
