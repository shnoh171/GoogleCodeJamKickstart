#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/2609

int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << endl << lcm(a, b) << endl;

	return 0;
}

int gcd(int a, int b) 
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
