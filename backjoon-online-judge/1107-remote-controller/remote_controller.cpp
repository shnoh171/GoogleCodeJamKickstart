#include <iostream>
using namespace std;

const int min_val = 0;

int GetOrder(int number); // assume number >= 0	
bool IsPossible(int number, int enable[]);
int FindUpper(int number, int enable[], int limit);
int FindLower(int number, int enable[]);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, enable[10];
	cin >> n >> m;
	for (int i = 0; i < 10; ++i) enable[i] = true;
	for (int i = 0; i < m; ++i) {
		int channel;
		cin >> channel;
		enable[channel] = false;
	}

	int upper_limit = n + abs(n-100);
	int upper = FindUpper(n, enable, upper_limit);
	int lower = FindLower(n, enable);

	int res = abs(n - 100);
	if (upper <= upper_limit)
		res = min(res, abs(n - upper) + GetOrder(upper));
	if (lower >= min_val)
		res = min(res, abs(n - lower) + GetOrder(lower));
		
	cout << res << "\n";

	return 0;
}

int GetOrder(int number)
{
	if (number == 0) return 1;

	int ret = 0;
	while (number > 0) {
		number /= 10;
		++ret;
	}
	return ret;
}

bool IsPossible(int number, int enable[])
{
	do {
		if (enable[number%10] == false) return false;
		number /= 10;
	} while (number > 0);
	return true;
}

int FindUpper(int number, int enable[], int limit)
{
	while (!IsPossible(number, enable)) {
		++number;
		if (number > limit) break;
	}
	return number;
}

int FindLower(int number, int enable[])
{
	while (!IsPossible(number, enable)) {
		--number;
		if (number < min_val) break;
	}
	return number;
}
