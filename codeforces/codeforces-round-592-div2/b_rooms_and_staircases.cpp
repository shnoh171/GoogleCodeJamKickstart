#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		string stairs;
		cin >> stairs;

		int leftmost = 0;
		while (leftmost < n && stairs[leftmost] == '0') {
			++leftmost;
		}
		
		int rightmost = n - 1;
		while (rightmost >= 0 && stairs[rightmost] == '0') {
			--rightmost;
		}

		if (leftmost == n) {
			cout << n << "\n";
		} else {
			int unable = min(leftmost, n - rightmost - 1);
			cout << 2 * (n - unable) << "\n";
		}
	}

	return 0;
}
