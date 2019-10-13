#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// Incomplete

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long n, p, w, d;
	cin >> n >> p >> w >> d;

	long long x_min = max((long long)0, (p - n*d) / w - 1);
	long long x_max = p / w;

	long long x_base;
	bool flag = false;

	set<long long> s;

	for (int x = x_min; x <= x_max; ++x) {
		long long leftover = p - x*w;

		if (s.find(leftover % d) != s.end()) {
			cout << "-1\n";
			return 0;
		}

		if (leftover % d == 0 && x + leftover / d <= n)	{
			cout << x << " " << leftover / d << " " << n - x - leftover / d << "\n";
			return 0;
		}

		s.insert(leftover % d);

		if (leftover % d == 0) {
			if (!flag) {
				x_base = x;
				flag = true;
				s = set<long long>();
			} else {
				int delta = x_base - x;
			}
		}
	}

	cout << "-1\n";

	return 0;
}

/*

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long n, p, w, d;
	cin >> n >> p >> w >> d;

	long long x_min = max((long long)0, (p - n*d) / w - 1);
	long long x_max = p / w;

	set<long long> s;

	for (int x = x_min; x <= x_max; ++x) {
		long long leftover = p - x*w;

		if (s.find(leftover % d) != s.end()) {
			cout << "-1\n";
			return 0;
		}

		if (leftover % d == 0 && x + leftover / d <= n)	{
			cout << x << " " << leftover / d << " " << n - x - leftover / d << "\n";
			return 0;
		}

		s.insert(leftover % d);

		if (leftover % d == 0) {
			s = set<long long>();
		}
	}

	cout << "-1\n";

	return 0;
}
*/