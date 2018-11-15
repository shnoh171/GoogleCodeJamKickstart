#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/11652

int main()
{
	long long a = 1;

	int array[100000000000];

	for (int i = 0; i < 62; ++i) a *=2;

	cout << a << endl;

	return 0;
}
