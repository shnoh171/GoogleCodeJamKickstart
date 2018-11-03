#include <iostream>
#include <string>

// https://www.acmicpc.net/problem/10162

using namespace std;

int main() 
{
	const int add_time[3] = {300, 60, 10};
	int num[3];

	int val;
	cin >> val; 

	if (val % add_time[2] != 0) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i != 3; ++i) {
		num[i] = val / add_time[i];
		val -= num[i] * add_time[i];
	}

	cout << num[0] << " " << num[1] << " " << num[2] << endl;

	return 0;
}

