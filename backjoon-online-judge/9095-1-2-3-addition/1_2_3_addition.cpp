#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int input[T]; 
	for (int i = 0; i < T; ++i)
		cin >> input[i];

	int max = *max_element(input, input + T);

	int d[max+1] = { 0, };
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= max; ++i)
		d[i] = d[i-3] + d[i-2] + d[i-1];

	for (int i = 0; i < T; ++i)
		cout << d[input[i]] << endl;

	return 0;
}
