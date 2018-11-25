#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1074

int NthVisit(int n, int r, int c);

int main()
{
	ios_base::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;

	cout << NthVisit(n, r, c) << "\n";

	return 0;
}

int NthVisit(int n, int r, int c) {
	if (n == 0) return 0;

	if (r < (1 << n-1) && c < (1 << n-1))
		return NthVisit(n-1, r, c);
	else if (r < (1 << n-1) && c >= (1 << n-1))
		return (1 << n-1) * (1 << n-1) + NthVisit(n-1, r, c - (1 << n-1));
	else if (r >= (1 << n-1) && c < (1 << n-1))
		return 2 * (1 << n-1) * (1 << n-1) + NthVisit(n-1, r - (1 << n-1), c);
	else
		return 3 * (1 << n-1) * (1 << n-1) + NthVisit(n-1, r - (1 << n-1), c - (1 << n-1));
}

