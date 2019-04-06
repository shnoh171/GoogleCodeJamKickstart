#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int n;
		string s;
		cin >> n >> s;
		cout << "Case #" << i << ": ";
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == 'E') cout << 'S';
			else cout << 'E';
		}
		cout << "\n";
	}

	return 0;
}
