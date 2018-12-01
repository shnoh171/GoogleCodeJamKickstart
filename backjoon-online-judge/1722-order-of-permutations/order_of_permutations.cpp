#include <iostream>
#include <queue>
using namespace std;

// Incomplete

int factorial(int number);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, problem;
	cin >> n >> problem;

	priority_queue<int, vector<int>, greater<int> > numbers;
	for (int i = 1; i < n+1; ++i) numbers.push(i);

	if (problem == 1) {
		int k;
		cin >> k;

	} else if (problem == 2) {
		int list[n];
		for (int i = 0; i < n; ++i) cin >> list[i];

		int res = 1;
		for (int i = 0; i < n; ++i) {
			priority_queue<int, vector<int>, greater<int> >::iterator it = numbers.find(list[i]);
			res += (it - numbers.begin()) * factorial (n-i-1);
		}
	}

	return 0;
}

int factorial(int number)
{
	if (number == 0) return 1;
	if (number == 1) return 1;
	else return number * factorial(number - 1);
}
