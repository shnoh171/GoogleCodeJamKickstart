#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetMaxCows(int idx, int acc, const vector<int> &cow);
bool IsCarry(int num1, int num2);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> cow(n);
	for (int i = 0; i < n; ++i) cin >> cow[i];

	cout << GetMaxCows(0, 0, cow) << "\n";

	return 0;
}

int GetMaxCows(int idx, int acc, const vector<int> &cow)
{
	if (idx == cow.size()) return 0;

	int curr = cow[idx];
	if (!IsCarry(acc, curr)) {
		int ret = 1 + GetMaxCows(idx + 1, acc + curr, cow);
		ret = max(ret, GetMaxCows(idx + 1, acc, cow));
		return ret;
	}
	else {
		return GetMaxCows(idx + 1, acc, cow);
	}
}

bool IsCarry(int num1, int num2)
{
	while (num1 > 0 && num2 > 0) {
		if (num1 % 10 + num2 % 10 >= 10)
			return true;
		num1 /= 10;
		num2 /= 10;
	}
	return false;
}