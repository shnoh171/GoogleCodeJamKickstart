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

	int list[n];
	for (int i = 0; i < n; ++i) list[i] = i+1;;

	do {
		for (int i = 0; i < n; ++i) cout << list[i] << " ";
		cout << "\n";
	} while(next_permutation(list, list+n)); 

	return 0;
}
