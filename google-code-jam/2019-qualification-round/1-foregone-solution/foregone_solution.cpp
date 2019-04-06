#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	
	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;

		int num1 = 0, num2 = 0;
		int order = 1;
		while (n > 0) {
			if (n % 10 != 4) {
				num1 += ((n % 10) * order);
			} else {
				num1 += ((n % 10 - 1) * order);
				num2 += order;
			}
			n = n / 10;
			order = order * 10;
		}

		cout << "Case #" << i << ": " << num1 << " " << num2 << "\n";
	}

	return 0;
}
