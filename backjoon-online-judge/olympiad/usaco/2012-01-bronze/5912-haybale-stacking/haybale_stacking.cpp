#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> stack_inc(n + 1);
	vector<int> stack_dec(n + 1);
	vector<int> stack(n + 1);
	for (int i = 1; i <= n; ++i) {
		stack_inc[i] = 0;
		stack_dec[i] = 0;
		stack[i] = 0;
	}

	while (k--) {
		int a, b;
		cin >> a >> b;
		++stack_inc[a];
		++stack_dec[b];
	}

	int curr = 0;
	for (int i = 1; i <= n; ++i) {
		curr += stack_inc[i];
		stack[i] = curr;
		curr -= stack_dec[i];
	}

	sort(stack.begin(), stack.end());

	cout << stack[(n + 1) / 2] << "\n";

	return 0;
}
