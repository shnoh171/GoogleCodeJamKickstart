#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, x;
	cin >> N >> x;
	vector<int> a(N);

	for (int i = 0; i < N; ++i) cin >> a[i];
	
	sort(a.begin(), a.end());

	int happy_cnt = 0;
	while (x > 0 && happy_cnt < a.size()) {
		x -= a[happy_cnt];
		if (x >= 0) ++happy_cnt;
	}
	if (x > 0) --happy_cnt;

	cout << happy_cnt << endl;

	return 0;
}
