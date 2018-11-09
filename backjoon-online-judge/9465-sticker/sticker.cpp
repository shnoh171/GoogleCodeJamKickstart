#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/9465

int main()
{
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int n;
		cin >> n;
		int input[2][n];
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < n; ++k)
				cin >> input[j][k]; 

		int d[n][3]; // d[][0]: 00, d[][1]: 10, d[][2]: 01
		d[0][0] = 0; 
		d[0][1] = input[0][0]; 
		d[0][2] = input[1][0];
		for (int j = 1; j < n; ++j) {
			d[j][0] = max(d[j-1][0], d[j-1][1]);
			d[j][0] = max(d[j][0], d[j-1][2]);
			d[j][1] = max(d[j-1][2] + input[0][j], d[j-1][0] + input[0][j]);
			d[j][2] = max(d[j-1][1] + input[1][j], d[j-1][0] + input[1][j]);
		}

		int ret = max(d[n-1][0], d[n-1][1]);
		ret = max(ret, d[n-1][2]);
		cout << ret << endl;
	}

	return 0;
}
