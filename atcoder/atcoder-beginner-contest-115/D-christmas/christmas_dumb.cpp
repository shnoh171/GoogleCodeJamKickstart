#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, x;
	cin >> n >> x;

	string d[n+1];
	d[0] = "P";
	for (long long i = 1; i < n+1; ++i)
		d[i] = "B" + d[i-1] + "P" + d[i-1] + "B";

	long long count = 0;
	for (long long i = 0; i < x; ++i)
		if (d[n][i] == 'P') ++count;

	cout << count << "\n";

	return 0;
}
