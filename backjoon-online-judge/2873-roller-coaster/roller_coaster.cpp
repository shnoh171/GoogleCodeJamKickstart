#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2873

int main()
{
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;

	int joy[r][c];

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cin >> joy[i][j];

	if (r % 2 == 1) {
		while (r != 1) {
			for (int i = 0; i < c-1; ++i) cout << 'R';
			cout << 'D';
			for (int i = 0; i < c-1; ++i) cout << 'L';
			cout << 'D';

			r -= 2;
		}

		for (int i = 0; i < c-1; ++i) cout << 'R';
		cout << "\n";

		return 0;
	} else if (c % 2 == 1) {
		while (c != 1) {
			for (int i = 0; i < r-1; ++i) cout << 'D';
			cout << 'R';
			for (int i = 0; i < r-1; ++i) cout << 'U';
			cout << 'R';

			c -= 2;
		}

		for (int i = 0; i < r-1; ++i) cout << 'D';
		cout << "\n";

		return 0;
	}

	int min_val = 1001; // loose bound
	int min_y, min_x;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (((i+j) % 2 == 1) && (joy[i][j] < min_val)) {
				min_val = joy[i][j];
				min_y = i;
				min_x = j;
			}
		}
	}

	int first_height = (min_y % 2 == 1) ? min_y - 1 : min_y;
	int second_width = (min_x % 2 == 1) ? min_x - 1 : min_x;
	int second_height = r - first_height;
	int third_width = c - second_width - 2;
	int fourth_width =  c - second_width;
	int fourth_height = second_height - 2;

	/*
	cout << "min_y = " << min_y << endl;
	cout << "min_x = " << min_x << endl;
	cout << "first height = " << first_height << endl;
	cout << "second width = " << second_width << endl;
	cout << "second height = " << second_height << endl;
	cout << "third width = " << third_width << endl;
	cout << "fourth width = " << fourth_width << endl;
	cout << "fourth height = " << fourth_height << endl;
	*/

	for (int i = 0; i < first_height/2; ++i) {
		for (int j = 0; j < c-1; ++j) cout << 'R';
		cout << 'D';
		for (int j = 0; j < c-1; ++j) cout << 'L';
		cout << 'D';
	}

	for (int i = 0; i < second_width/2; ++i) {
		for (int j = 0; j < second_height-1; ++j) cout << 'D';
		cout << 'R';
		for (int j = 0; j < second_height-1; ++j) cout << 'U';
		cout << 'R';
	}

	if (min_y % 2 == 0) cout << "DR";
	else cout << "RD";

	if (third_width != 0) {
		cout << "R";
	} else if (fourth_height != 0) {
		cout << "D";
	}

	for (int i = 0; i < third_width/2 - 1; ++i) cout << "URDR";
	if (third_width != 0) {
		if (fourth_height == 0) {
			cout << "URD";
		} else {
			cout << "URDD";
		}
	}

	for (int i = 0; i < fourth_height/2 - 1; ++i) {
		for (int j = 0; j < fourth_width-1; ++j) cout << 'L';
		cout << 'D';
		for (int j = 0; j < fourth_width-1; ++j) cout << 'R';
		cout << 'D';
	}

	if (fourth_height != 0) {
		for (int j = 0; j < fourth_width-1; ++j) cout << 'L';
		cout << 'D';
		for (int j = 0; j < fourth_width-1; ++j) cout << 'R';
	}

	cout << "\n";

	return 0;
}
