#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// Q: https://code.google.com/codejam/contest/9234486/dashboard#s=p0

long long prev_no_odd(long long number);
long long next_no_odd(long long number);

int main()
{
	//ifstream fin("dataset/test.in");
	//ofstream fout("dataset/test.out");
	//ifstream fin("dataset/A-small-practice.in");
	//ofstream fout("dataset/A-small-practice.out");
	ifstream fin("dataset/A-large-practice.in");
	ofstream fout("dataset/A-large-practice.out");

	int num;
	fin >> num;

	for (int i = 0; i < num; ++i) {
		long long input;
		fin >> input;

		fout << "Case #" << i + 1 << ": ";
		fout << min(input - prev_no_odd(input), next_no_odd(input) - input) << endl;;
		//cout << input << " " << prev_no_odd(input) << " " << next_no_odd(input) << endl;
	}

	return 0;
}

long long prev_no_odd(long long number) {
	vector<int> number_v;

	while (number > 0) {
		number_v.push_back(number % 10);
		number = number / 10;
	}
	reverse(number_v.begin(), number_v.end());

	int size = number_v.size();

	int i = 0;
	while (i < size) {
		if (number_v[i] % 2 == 1) {
			--number_v[i];
			++i;
			break;
		}
		++i;
	}

	while (i < size)
		number_v[i++] = 8;

	long long ret = 0;
	for (int i = 0; i < size; ++i) {
		ret *= 10;
		ret += number_v[i];
	}

	return ret;
}

long long next_no_odd(long long number) {
	vector<int> number_v;

	while (number > 0) {
		number_v.push_back(number % 10);
		number = number / 10;
	}
	reverse(number_v.begin(), number_v.end());

	int size = number_v.size();

	int i = 0;
	while (i < size) {
		if (number_v[i] % 2 == 1) {
			++number_v[i];
			++i;
			break;
		}
		++i;
	}

	if (number_v[i - 1] == 10) {
		number_v[i - 1] = 0;

		int j;
		for (j = i - 2; j >= 0; --j) {
			if (number_v[j] == 8) {
				number_v[j] = 0;
			} else {
				number_v[j] += 2;
				break;
			}
		}

		if (j < 0) {
			number_v.insert(number_v.begin(), 2);
			size = number_v.size();
		}
	}

	while (i < size)
		number_v[i++] = 0;

	long long ret = 0;
	for (int i = 0; i < size; ++i) {
		ret *= 10;
		ret += number_v[i];
	}

	return ret;
}
