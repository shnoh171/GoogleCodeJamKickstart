#include <iostream>
#include <string>
using namespace std;

// https://www.acmicpc.net/problem/1541

int main()
{
	ios_base::sync_with_stdio(false);

	string formula;
	cin >> formula;

	int sum = 0;
	int number = 0;
	bool is_negative = false;
	for (int i = 0; i < formula.size(); ++i) {
		if (formula[i] != '-' && formula[i] != '+') {
			number *= 10;
			number += formula[i] - '0';
		} else if (is_negative) {
			sum -= number;
			number = 0;
		} else {
			sum += number;
			number = 0;
		}

		if (!is_negative && formula[i] == '-')
			is_negative = true;
	}

	sum = is_negative ? sum - number : sum + number;

	cout << sum << "\n";

	return 0;
}


