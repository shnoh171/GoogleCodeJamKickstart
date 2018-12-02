#include <iostream>
using namespace std;

const int max_val = 15*28*29;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m;
	cin >> e >> s >> m;

	if (s == 28) s = 0;
	if (m == 19) m = 0;

	while (e < max_val+1) {
		if (e % 28 == s && e % 19 == m) {
			cout << e << "\n";
			return 0;
		}
		e += 15;
	}

	return 0;
}
