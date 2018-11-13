#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/9613

int gcd(int a, int b);
//long long lcm(int a, int b);

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		vector<int> nums(n);
		long long sum = 0;
		
		for (int j = 0; j < n; ++j) cin >> nums[j];

		for (int j = 0; j < n; ++j) {
			for (int k = j+1; k < n; ++k) {
				sum += gcd(nums[j], nums[k]);
			}
		}
		cout << sum << endl;
	}

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
/*
long long lcm(int a, int b) {
	return ((long long)a * (long long)b) / gcd(a, b);
}
*/
