#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsValidFolding(int l_base, int r_base, int rope_size, const vector<int> &rope);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> rope(n);
	for (int i = 0; i < n; ++i) cin >> rope[i];
	sort(rope.begin(), rope.end());

	if (rope.size() == 1) {
		cout << "0\n";
	}
	else {
		int count = 0;

		for (int i = 1; i < n - 1; ++i)
			if (IsValidFolding(i, i, l, rope))
				++count;

		for (int i = 0; i < n - 1; ++i)
			if (IsValidFolding(i, i + 1, l, rope))
				++count;

		cout << count << "\n";
	}

	return 0;
}

bool IsValidFolding(int l_base, int r_base, int rope_size, const vector<int> &rope)
{
	int l = l_base;
	int r = r_base;

	while (l >= 0 && r < rope.size())
		if (rope[l_base] - rope[l--] != rope[r++] - rope[r_base])
			return false;

	return true;
}