#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool IsRange(int index, int size) { return index >= 0 && index < size; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string seq;
	cin >> seq;
	int n = seq.size();
	bool is_palindrome[n][n];
	memset(is_palindrome, false, (n*n)*sizeof(bool));

	for (int i = 0; i < n; ++i) {
		is_palindrome[i][i] = true;
		int delta = 1;
		while (IsRange(i-delta, n) && IsRange(i+delta, n)) {
			if (seq[i-delta] != seq[i+delta])
				break;
			else
				is_palindrome[i-delta][i+delta] = true;
			++delta;
		}
	}
	
	for (int i = 0; i < n-1; ++i) {
		if (seq[i] == seq[i+1])
			is_palindrome[i][i+1] = true;
		else
			continue;
		int delta = 1;
		while (IsRange(i-delta, n) && IsRange(i+1+delta, n)) {
			if (seq[i-delta] != seq[i+1+delta])
				break;
			else
				is_palindrome[i-delta][i+1+delta] = true;
			++delta;
		}
	}

	int d[n];
	const int max_val = n+1;
	d[0] = 1;
	for (int i = 1; i < n; ++i) {
		d[i] = is_palindrome[0][i] ? 1 : max_val;
		if (d[i] != 1) {
			for (int j = 0; j < i; ++j) {
				if (is_palindrome[j+1][i]) {
					d[i] = min(d[i], d[j] + 1);
				}
			}
		}
	}

	cout << d[n-1] << "\n";

	return 0;
}
