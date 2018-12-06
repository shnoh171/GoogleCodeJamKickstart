#include <iostream>
#include <vector>
using namespace std;

// number right before 'time'
long long GetNumberOfRides(long long time, const vector<int>& cars); 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n;
	int m;
	cin >> n >> m;
	vector<int> cars(m+1);
	for (int i = 1; i < m+1; ++i) cin >> cars[i];

	long long left = 0;
	long long right = 30*n;
	long long ans_time = 0;
	long long ans_num = 0;
	
	while (left <= right) {
		long long mid_time = (left + right) / 2;
		long long mid_num = GetNumberOfRides(mid_time, cars); 

		if (mid_num <= n) {
			ans_time = mid_time;
			ans_num = mid_num;
			left = mid_time + 1;
		} else {
			right = mid_time - 1;
		}
	}

	if (ans_num == n) {
		--ans_time;
		while (true) {
			for (int i = m; i >= 1; --i) {
				if (ans_time % cars[i] == 0) {
					cout << i << "\n";
					return 0;
				}
			}
			--ans_time;
		}
	}

	while (true) {
		for (int i = 1; i < m+1; ++i) {
			if (ans_time % cars[i] == 0) {
				++ans_num;
				if (ans_num == n) {
					cout << i << "\n";
					return 0;
				}
			}
		}
		++ans_time;
	}
}

long long GetNumberOfRides(long long time, const vector<int>& cars)
{
	if (time == 0) return 0;

	long long ret = 0;
	for (int i = 1; i < cars.size(); ++i)
		ret += (time-1)/cars[i] + 1;
	return ret;
}
