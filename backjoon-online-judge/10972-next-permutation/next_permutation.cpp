#include <iostream>
#include <algorithm>
using namespace std;

bool NextPermutation(int list[], int n);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int list[n];
	for (int i = 0; i < n; ++i) cin >> list[i];

	if (next_permutation(list, list+n))
		for (int i = 0; i < n; ++i) cout << list[i] << " ";
	else
		cout << "-1";

	cout << "\n";

	return 0;
}

bool NextPermutation(int list[], int n)
{

}
