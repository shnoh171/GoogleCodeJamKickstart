#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool IsRampNumber(string num);
long long GetNumOfLessRampNumber(string num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		string num;
		cin >> num;
		if (!IsRampNumber(num)) {
			cout << "-1\n";
		}
		else {
			cout << GetNumOfLessRampNumber(num) << "\n";
		}
	}

	return 0;
}

bool IsRampNumber(string num)
{
	for (int i = 0; i < num.size() - 1; ++i) {
		if (num[i] > num[i + 1]) return false;
	}
	return true;
}

long long GetNumOfLessRampNumber(string num)
{
	long long d[80][10];
	for (int i = 0; i < 10; ++i) {
		if (i < num[0] - '0') d[0][i] = 1;
		else d[0][i] = 0;
	}

	for (int i = 1; i < num.size(); ++i) {
		for (int j = 0; j < 10; ++j) {
			d[i][j] = 0;
			for (int k = 0; k <= j; ++k)
				d[i][j] += d[i - 1][k];
			if (j >= num[i - 1] - '0' && j < num[i] - '0')
				++d[i][j];
		}
	}

	long long res = 0;
	for (int i = 0; i < 10; ++i)
		res += d[num.size()-1][i];
	
	return res;
}