#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = i; j < n; ++j) {
			sum += a[j];
			if (sum == m) {
				++count;
				break;
			} else if (sum > m) {
				break;
			}
		}
	}

	cout << count << '\n';

	return 0;
}
