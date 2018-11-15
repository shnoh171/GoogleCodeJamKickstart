#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/11652

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	
	long long nums[n];
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	sort(nums, nums+n);
	
	int curr = 0;
	while (curr < n && nums[0] == nums[curr]) ++curr;
	long long most_freq_num = nums[0];
	int most_freq_cnt = curr;

	for (int i = curr; i < n+1; ++i) {
		if (i >= n || nums[curr] != nums[i]) {
			if (most_freq_cnt < i - curr) {
				most_freq_num = nums[curr];
				most_freq_cnt = i - curr;
			}
			curr = i;
		}
	}	

	cout << most_freq_num << "\n";

	return 0;
}
