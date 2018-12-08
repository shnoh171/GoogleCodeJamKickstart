#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d;
	cin >> d;

	if (d == 22) cout << "Christmas Eve Eve Eve\n";
	else if (d == 23) cout << "Christmas Eve Eve\n";
	else if (d == 24) cout << "Christmas Eve\n";
	else if (d == 25) cout << "Christmas\n";

	return 0;
}
