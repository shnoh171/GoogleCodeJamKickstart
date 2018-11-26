#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10563

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

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

		if (right - one == 1)
			num_when_left_first = n - 1;
		else
			num_when_left_first = n - (right - one);

		if (one - left == 1)
			num_when_right_first = n - 1;
		else
			num_when_right_first = n - (one - left);

		bool alice_win_when_left_first = (num_when_left_first % 2 == 0);
		bool alice_win_when_right_first = (num_when_right_first % 2 == 0);

		/*
		cout << "num_when_left_first = " << num_when_left_first << endl;
		cout << "num_when_right_first = " << num_when_right_first << endl;
		cout << "alice_win_when_left_first = " << alice_win_when_left_first << endl;
		cout << "alice_win_when_right_first = " << alice_win_when_right_first << endl;
		*/

		if (one == numbers) {
			if (alice_win_when_left_first)
				cout << "Alice\n";
			else
				cout << "Bob\n";
		} else if (one == numbers + n - 1) {
			if (alice_win_when_right_first)
				cout << "Alice\n";
			else
				cout << "Bob\n";
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

			int left_size = one - left - 1;
			int right_size = right - one - 1;

			/*
			cout << "left_size = " << left_size << endl;
			cout << "right_size = " << right_size << endl;
			*/

			if (alice_win_when_left_first && alice_win_when_right_first)
				cout << "Alice\n";
			else if (alice_win_when_left_first && left_size <= right_size)
				cout << "Alice\n";
			else if (alice_win_when_right_first && right_size <= left_size)
				cout << "Alice\n";
			else
				cout << "Bob\n";
		}
	}

	return 0;
}
