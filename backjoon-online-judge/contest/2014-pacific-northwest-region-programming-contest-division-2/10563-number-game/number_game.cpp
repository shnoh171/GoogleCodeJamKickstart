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


		int num_when_left_first;
		int num_when_right_first;

		if (right - one == 2)
			num_when_left_first = n - 1;
		else
			num_when_left_first = n - (right - one - 1);

		if (one - left == 2)
			num_when_right_first = n - 1;
		else
			num_when_right_first = n - (one - left - 1);

		cout << "num_when_left_first = " << num_when_left_first << endl;
		cout << "num_when_right_first = " << num_when_right_first << endl;

		if (one == numbers) {
			if (num_when_left_first % 2 == 0)
				cout << "Alice\n";
			else
				cout << "Bob\n";
			return 0;
		} else if (one == numbers + n - 1) {
			if (num_when_right_first % 2 == 0)
				cout << "Alice\n";
			else
				cout << "Bob\n";
			return 0;
		}


		/*


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
		*/
	}

	return 0;
}
