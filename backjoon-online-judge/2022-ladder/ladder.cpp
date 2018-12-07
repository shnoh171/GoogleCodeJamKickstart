#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double x, y, c;
	cin >> x >> y >> c;

	double left = 0;
	double right = min(x, y);

	while (true) {
		double mid = (left + right) / 2;
		double h_l = sqrt(pow(x, 2) - pow(mid, 2));
		double h_r = sqrt(pow(y, 2) - pow(mid, 2));
		double c_curr = h_l * h_r / (h_l + h_r);
		
		//cout << abs(c - c_curr) << endl;
		//cout << left << " " << mid << " " << right << endl;

		if (abs(c - c_curr) < 0.00000001) {
			cout << fixed << setprecision(3) << mid << "\n";
			return 0;
		}

		if (c_curr > c) left = mid;
		else right = mid;
	}
}
