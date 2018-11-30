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
	
	if (NextPermutation(list, n))
		for (int i = 0; i < n; ++i) cout << list[i] << " ";
	else
		cout << "-1";

	cout << "\n";
	/*
	int list[n];
	for (int i = 0; i < n; ++i) list[i] = i+1;;

	int list_cmp[n];
	for (int i = 0; i < n; ++i) list_cmp[i] = i+1;;

	do {
		for (int i = 0; i < n; ++i)
			if (list[i] != list_cmp[i]) {
				cout << "list: ";
				for (int j = 0; j < n; ++j) cout << list[j] << " ";
				cout << "\n";
				cout << "list_cmp: ";
				for (int j = 0; j < n; ++j) cout << list_cmp[j] << " ";
				cout << "\n";
				cout << "previous: ";
				prev_permutation(list_cmp, list_cmp+n);
				for (int j = 0; j < n; ++j) cout << list_cmp[j] << " ";
				cout << "\n";

				return 1;
			}
		next_permutation(list_cmp, list_cmp+n);
	} while(NextPermutation(list, n)); 
	*/

	return 0;
}

bool NextPermutation(int list[], int n)
{
	int pivot = n-1;
	while (pivot > 0 && list[pivot] < list[pivot-1])
		--pivot;

	if (pivot == 0) return false;

	int index = n-1;
	while (list[pivot-1] > list[index]) --index;

	swap(list[pivot-1],list[index]);

	for (int i = 0; i < (n - pivot) / 2; ++i) {
		swap(list[pivot+i], list[n-1-i]);
	}

	return true;
}
