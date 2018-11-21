#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10610

int main()
{
	ios_base::sync_with_stdio(false);

	string n;
	cin >> n;

	bool is_zero = false;
	vector<int> digits;

	for (int i = 0; i < n.size(); ++i) {
		int digit = n[i] - '0';
		if (digit == 0) is_zero = true;
		digits.push_back(digit);
	}

	if (!is_zero || accumulate(digits.begin(), digits.end(), 0) % 3) {
		cout << -1 << "\n";
	} else {
		sort(digits.rbegin(), digits.rend());
		for (int i = 0; i < digits.size(); ++i) cout << digits[i];
		cout << "\n";
	}

	return 0;
}
