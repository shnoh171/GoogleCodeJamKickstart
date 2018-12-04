#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		long long a, b, k;
		cin >> a >> b >> k;
		cout << ((k+1)/2)*a - (k/2)*b << "\n";
	}

	return 0;
}
