#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	int next_white = 0;
	while (next_white < s.size() && s[next_white] == 'W')
		++next_white;

	if (next_white == s.size()) {
		cout << "0\n";
		return 0;
	}

	long long count = 0;
	for (int i = next_white; i < s.size(); ++i) {
		if (s[i] == 'W') {
			count += i - next_white;
			swap(s[next_white], s[i]);
			++next_white;
		}
	}

	cout << count << "\n";

	return 0;
}
