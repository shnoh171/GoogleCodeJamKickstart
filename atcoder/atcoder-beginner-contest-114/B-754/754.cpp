#include <iostream>
#include <string>
using namespace std;

const int max_val = 1000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int diff_min = max_val;

	string s;
	cin >> s;

	int digits[s.size()];
	for (int i = 0; i < s.size(); ++i)
		digits[i] = s[i] - '0';

	for (int i = 0; i < s.size()-2; ++i) {
		int number = digits[i] * 100 + digits[i+1] * 10 + digits[i+2];
		diff_min = min(diff_min, abs(number-753));
	}

	cout << diff_min << "\n";

	return 0;
}
