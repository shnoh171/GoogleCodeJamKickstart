#include <iostream>
#include <vector>
using namespace std;

// https://algospot.com/judge/problem/read/FESTIVAL
// brute force

int main()
{
	int c;
	cin >> c;


	for (int i = 0; i < c; ++i) {
		int n, l;
		cin >> n >> l;
		vector<int> rent(n);
		for (int j = 0; j < n; ++j) cin >> rent[j];

		double min_avg = 0;
		for (int j = 0; j < n; ++j) min_avg += rent[j];

		for (int j = 0; j <= n-l; ++j) {
			int sum = 0, cnt = 0;
			for (int k = j; k <= j+l-1; ++k) {
				sum += rent[k];
				++cnt;
			}

			cout << "sum: " << sum << ", cnt: " << cnt << endl;
			//cout << (double)sum / (double)cnt;
			min_avg = min(min_avg, (double)sum / (double)cnt);

			for (int k = j+l; k < n; ++k) {
				sum += rent[k];
				++cnt;
				cout << "sum: " << sum << ", cnt: " << cnt << endl;
				min_avg = min(min_avg, (double)sum / (double)cnt);
			}
		}
	
		cout << fixed;
		cout.precision(10);
		cout << min_avg << endl;
	}

	return 0;
}

