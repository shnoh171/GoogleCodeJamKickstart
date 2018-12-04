#include <iostream>
using namespace std;

int main()
{
	int  n, m, l;
	//bool flag = false;
	cin >> n >> m >> l;

	int a[n+1];
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 0; i < m; ++i) {
		int cmd;
		cin >> cmd;

		if (cmd == 0) {
			//if (flag == true) {
			//	cout << 1 << endl;
			//	continue;
			//}

			int cnt = 0;
			//bool start = false;
			
			if (a[1] > l) ++cnt;
			int j;
			for (j = 2; j <= n; ++j) {
				if (a[j-1] <= l && a[j] > l) ++cnt;
			}
			//if (a[1] > l && a[n] > l && cnt == 1) flag = true;
			cout << cnt << endl;
		} else if (cmd == 1) {
			int p, d;
			cin >> p >> d;

			a[p] += d;
			if (a[p] > l) a[p] = l + 1;
		}
	}

	return 0;
}
