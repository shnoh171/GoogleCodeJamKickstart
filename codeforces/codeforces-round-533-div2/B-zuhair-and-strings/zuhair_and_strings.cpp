#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	int alphabet_count[26] = {};
	int count = 0;
	char prev = '.';

	for (int i = 0; i < n; ++i) {
		char curr = s[i];

		if (curr == prev) {
			++count;
		} else {
			count = 1;
		}

		if (count == k) {			
			count = 0;
			++alphabet_count[curr-'a'];
		}

		prev = curr;
	}

	cout << *max_element(alphabet_count, alphabet_count+26) << "\n";

	return 0;
}
