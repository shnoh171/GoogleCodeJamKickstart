#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<int> outputs;
	int a, i = 1;
	cin >> a;

	while (outputs.find(a) == outputs.end()) {
		outputs.insert(a);
		if (a % 2) a = 3 * a + 1;
		else a = a / 2;
		++i;
	}

	cout << i << "\n";

	return 0;
}
