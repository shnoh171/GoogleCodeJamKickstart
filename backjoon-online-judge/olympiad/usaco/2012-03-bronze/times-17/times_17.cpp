#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string AddNum(string a, string b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string input;
	cin >> input;

	string res = input + "0000";
	res = AddNum(res, input);

	for (int i = 0; i < res.size(); ++i) cout << res[i];
	cout << "\n";

	return 0;
}

string AddNum(string a, string b)
{
	string ret;
	int carry = 0;
	for (int i = 0; i < a.size(); ++i) {
		int idx_a = a.size() - i - 1;
		int idx_b = b.size() - i - 1;

		if (idx_b >= 0) {
			int val = a[idx_a] - '0' + b[idx_b] - '0' + carry;
			if (val >= 2) {
				ret += (val - 2 + '0');
				carry = 1;
			}
			else {
				ret += (val + '0');
				carry = 0;
			}
		}
		else {
			int val = a[idx_a] - '0' + carry;
			if (val >= 2) {
				ret += (val - 2 + '0');
				carry = 1;
			}
			else {
				ret += (val + '0');
				carry = 0;
			}
		}
	}

	if (carry) ret += (1 + '0');

	reverse(ret.begin(), ret.end());

	return ret;
}