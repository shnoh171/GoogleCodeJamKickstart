#include <iostream>
using namespace std;

void print_path(int* p, int i, int n);

int main()
{
	int n;
	cin >> n;

	int p[n+1];
	for (int i = 2; i < n + 1; ++i) cin >> p[i];

	print_path(p, n, n);

	return 0;
}

void print_path(int* p, int i, int n) {
	if (i != 1) print_path(p, p[i], n);

	cout << i;
	if (i != n) cout << " ";
	else cout << endl;
}
