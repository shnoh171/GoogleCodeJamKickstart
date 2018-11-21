#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/1744

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int sequence[n];
	for (int i = 0; i < n; ++i) cin >> sequence[i];

	sort(sequence, sequence + n);

	long long res = 0;

	int index = 0;
	while (index < n && sequence[index] < 0) {
		if (index < n-1 && sequence[index+1] <= 0) {
			res += sequence[index] * sequence[index+1];
			index += 2;
		} else {
			res += sequence[index];
			++index;
		}
	}

	index = n-1;
	while (index >= 0 && sequence[index] > 0) {
		if (index >= 1 && sequence[index-1] > 1) {
			res += sequence[index] * sequence[index-1];
			index -= 2;
		} else {
			res += sequence[index];
			--index;
		}
	}

	cout << res << "\n";

	return 0;
}
