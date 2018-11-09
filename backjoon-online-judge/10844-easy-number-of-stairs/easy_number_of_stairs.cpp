#include <iostream>
using namespace std;

int num_of_stairs(int n, int m, int d[][10]);

int main()
{
	int n;
	cin >> n;
	int d[n+1][10];
	for (int i = 0; i < n+1; ++i)
		for (int j = 0; j < 10; ++j)
			d[i][j] = -1;

	int res = 0;
	for (int i = 0; i < 10; ++i) 
		res =  (res + (num_of_stairs(n, i, d) % 1000000000)) % 1000000000;

	cout << res << endl;;

	return 0;
}

int num_of_stairs(int n, int m, int d[][10]) {
	if (n == 1) {
		if (m == 0) return 0;
		else return 1;
	} else if (n == 2) {
		if (m == 0 || m == 1 || m == 9) return 1;
		else return 2;
	} else {
		if (m == 0) {
			if (d[n][m] < 0)
				d[n][m] = num_of_stairs(n-1, 1, d) % 1000000000;
			return d[n][m];
		} else if (m == 9) {
			if (d[n][m] < 0)
				d[n][m] = num_of_stairs(n-1, 8, d) % 1000000000;
			return d[n][m];
		} else {
			if (d[n][m] < 0) 
				d[n][m] = (num_of_stairs(n-1, m-1, d) % 1000000000 
						 + num_of_stairs(n-1, m+1, d) % 1000000000) % 1000000000;
			return d[n][m];
		}
	}
}
