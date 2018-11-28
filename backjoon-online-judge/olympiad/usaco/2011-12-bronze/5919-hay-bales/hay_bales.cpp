#include <iostream>
#include <numeric>
using namespace std;

// https://www.acmicpc.net/problem/5919

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int haybales[n];
	for (int i = 0; i < n; ++i) cin >> haybales[i];

	int avg = accumulate(haybales, haybales+n, 0) / n;

	int count = 0;
	for (int i = 0; i < n; ++i)
		if (haybales[i] < avg)
			count += avg - haybales[i];

	cout << count << "\n";

	return 0;
}
