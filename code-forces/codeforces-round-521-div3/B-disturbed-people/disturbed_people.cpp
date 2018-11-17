#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	int cnt = 0;
	for (int i = 2; i < n; ++i) {
		if (a[i-2] == 1 && a[i-1] == 0 && a[i] == 1) {
			a[i] = 0;
			++cnt;
		}
	}

	//cout << (cnt+1) / 2 << "\n";
	cout << cnt << "\n";

	return 0;
}
