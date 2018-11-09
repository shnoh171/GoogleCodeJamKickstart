#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/9465

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int n;
		cin >> n;
		int input[n][2];
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < n; ++k)
				cin >> input[k][j]; 

		int d[n][3]; // d[][0]: 00, d[][1]: 10, d[][2]: 01
		d[0][0] = 0; 
		d[0][1] = input[0][0]; 
		d[0][2] = input[0][1];
		for (int j = 1; j < n; ++j) {
			d[j][0] = max(d[j-1][0], d[j-1][1]);
			d[j][0] = max(d[j][0], d[j-1][2]);
			d[j][1] = max(d[j-1][2] + input[j][0], d[j-1][0] + input[j][0]);
			d[j][2] = max(d[j-1][1] + input[j][1], d[j-1][0] + input[j][1]);
		}

		int ret = max(d[n-1][0], d[n-1][1]);
		ret = max(ret, d[n-1][2]);
		cout << ret << endl;
	}

	return 0;
}
