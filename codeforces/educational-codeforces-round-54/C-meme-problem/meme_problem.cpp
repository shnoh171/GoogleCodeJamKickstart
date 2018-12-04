#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int t;
	cin >> t;

	cout << fixed;
	cout << setprecision(10);

	for (int i = 0; i < t; ++i) {
		int d;
		cin >> d;

		if (d == 0) {
			cout << "Y 0.0000000000 0.0000000000" << endl;
		} else if (d < 4) {
			cout << "N" << endl;
		} else if (d == 4) {
			cout << "Y 2.0000000000 2.0000000000" << endl;
		} else if (d > 4) {
			double a = ((double)d - sqrt((double)d * (double)d - 4. * (double)d)) / 2.;
			double b = ((double)d + sqrt((double)d * (double)d - 4. * (double)d)) / 2.;
			cout << "Y " << b << " " << a << endl;
		}
	}

	return 0;
}
