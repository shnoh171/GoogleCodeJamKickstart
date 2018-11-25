#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10563

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;


		int numbers[n];
		for (int j = 0; j < n; ++j) cin >> numbers[j];

		if (n == 1) {
			cout << "Alice\n";
			continue;
		}

		int *one = find(numbers, numbers+n, 1);
		int *left = one - 1;
		int *right = one + 1;

		if (right != numbers+n) {
			while (right+1 != numbers+n && *right > *(right+1)) {
				++right;
			}
		}

		if (left != numbers-1) {
			while (left-1 != numbers-1 && *left > *(left-1)) {
				--left;
			}
		}

		int left_able, left_unable, right_able, right_unable;
		if (one == numbers) {
			left_able = 0;
			left_unable = 0;
		} else {
			left_able = left - numbers + 1;
			left_unable = one - left - 1;
		}
		if (one == numbers + n - 1) {
			right_able = 0;
			right_unable = 0;
		} else {
			right_able = (numbers + n) - right;
			right_unable = right - one - 1;
		}

		cout << left_able << " " << left_unable << " " << right_unable << " " << right_able << endl;

		int left_last = left_able + right_unable + right_able;
		int right_last = left_able + left_unable + right_able;

		cout << left_last << " " << right_last << endl;

		if (left_last % 2 == 1 && right_last % 2 == 1) {
			cout << "Bob\n";
		} else if (left_last % 2 == 0 && right_last % 2 == 0) {
			cout << "Alice\n";
		} else {
			int *left = one - 1;
			int *right = one + 1;

			if (right != numbers+n) {
				while (right+1 != numbers+n && *right < *(right+1)) {
					++right;
				}
			}

			if (left != numbers-1) {
				while (left-1 != numbers-1 && *left < *(left-1)) {
					--left;
				}
			}

			int left_size, right_size;

			if (one == numbers) left_size = 0;
			else left_size = one - left - 1;

			if (one == numbers + n + 1) right_size = 0;
			else right_size = right - one - 1;

			if (left_last % 2 == 1 && left_size > right_size)
				cout << "Bob\n";
			else if (right_last % 2 == 1 && right_size > left_size)
				cout << "Bob\n";
			else
				cout << "Alice\n";
		}
	}

	return 0;
}
