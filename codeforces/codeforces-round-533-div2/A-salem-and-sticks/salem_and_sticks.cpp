#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 987654321;
int CalcCost(int a, int b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	int res_num;
	int res_len = inf;
	for (int i = 1; i <= 100; ++i) {
		int curr = 0;
		for (int j = 0; j < n; ++j) {
			curr += CalcCost(i, a[j]);
		}
		if (res_len > curr) {
			res_len = curr;
			res_num = i;
		}		
	}

	cout << res_num << " " << res_len << "\n";

	return 0;
}

int CalcCost(int a, int b)
{
	return max(0, abs(a-b) - 1);
}