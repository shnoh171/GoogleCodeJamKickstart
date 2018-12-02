#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	if (x == 7 || x == 5 || x == 3) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
