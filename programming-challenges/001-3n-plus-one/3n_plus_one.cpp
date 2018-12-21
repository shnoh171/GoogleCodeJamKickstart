#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

map<int, int> length;

int GetMaxLength(int number);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ofstream fout("test.out");

	length[1] = 1;

	int input1, input2;
	while (cin >> input1 >> input2) {
		int num1 = min(input1, input2);
		int num2 = max(input1, input2);

		int max_length = 0;
		for (int i = num1; i <= num2; ++i) {
			max_length = max(max_length, GetMaxLength(i));
		}
		cout << input1 << " " << input2 << " " << max_length << "\n";
	}


	return 0;
}

int GetMaxLength(int number)
{
	if (length.find(number) != length.end()) return length[number];

	int next = (number % 2 == 0) ? number / 2 : number * 3 + 1;
	int res = GetMaxLength(next) + 1;
	length[number] = res;

	return res;
}