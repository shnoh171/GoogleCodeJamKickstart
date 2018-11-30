#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2805

const int min_value = 0;
const int max_value = 2000000000;

long long GetLumberLength(int height, int trees[], int n);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int trees[n];
	for (int i = 0 ; i < n; ++i) cin >> trees[i];

	int left = 0;
	int right = max_value;
	int answer = min_value;

	while (left <= right) {
		int middle = ((long long)left + right) / 2;
		long long lumber_length = GetLumberLength(middle, trees, n);

		if (lumber_length >= m) {
			answer = max(answer, middle);
			left = middle + 1;
		} else {
			right = middle - 1;
		}
	}

	cout << answer << "\n";

	return 0;
}

long long GetLumberLength(int height, int trees[], int n)
{
	long long ret = 0;
	for (int i = 0; i < n; ++i)
		ret += max(0, trees[i] - height);
	return ret;
}
