#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int d[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> d[i][j];

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (d[i][k] == 1 && d[k][j] == 1)
					d[i][j] = 1;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
