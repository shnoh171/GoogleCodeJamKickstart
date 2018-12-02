#include <iostream>
#include <set>
using namespace std;

int GetOrder(int number);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number;
	cin >> number;

	int order = GetOrder(number);
	
	int d[4][order+1];

	d[0][0] = 1; d[1][0] = 0; d[2][0] = 0; d[3][0] = 0;
	d[0][1] = 3; d[1][1] = 1; d[2][1] = 0; d[3][1] = 0;
	for (int i = 2; i < order+1; ++i) {
		d[0][i] = 3*d[0][i-1];
		d[1][i] = d[0][i-1] + 2*d[1][i-1];
		d[2][i] = 2*d[1][i-1] + d[2][i-1];
		d[3][i] = 3*d[2][i-1];
	}

	/*
	cout << d[2][2] << " " << d[3][3] << endl;
	cout << d[0][2] << " " << d[1][2] << " " << d[2][2] << " " << d[3][2] << endl;
	cout << d[0][3] << " " << d[1][3] << " " << d[2][3] << " " << d[3][3] << endl;
	*/
	int digits[order];

	int temp = number;
	for (int i = order-1; i >= 0; --i) {
		digits[i] = temp % 10;
		temp /= 10;
	}

	set<int> remainings;
	remainings.insert(3);
	remainings.insert(5);
	remainings.insert(7);

	int res = 0;
	for (int i = 0; i < order; ++i) res += d[3][i];

	//cout << res << endl;

	for (int i = 0; i < order; ++i) {
		int length = order-i-1;

		if (i == order-1 && remainings.size() == 0) {
			int digit = digits[i];
			if (digit < 3) ;
			else if (digit < 5) res += 1;
			else if (digit < 7) res += 2;
			else res += 3;
			//cout << res << endl;
			break;
		} else if (i == order-1 && remainings.size() == 1) {
			int digit = digits[i];

			if (digit < 3) {
				;
			} else if (digit < 5) {
				if (remainings.find(3) != remainings.end())
					++res;
			} else if (digit < 7) {
				if (remainings.find(3) != remainings.end())
					++res;
				if (remainings.find(5) != remainings.end())
					++res;
			} else {
				if (remainings.find(3) != remainings.end())
					++res;
				if (remainings.find(5) != remainings.end())
					++res;
				if (remainings.find(7) != remainings.end())
					++res;
			}

			break;
		}
		//cout << "i = " << i << ", res = " << res << endl;

		if (digits[i] == 3) {
			if (remainings.find(3) != remainings.end())
				remainings.erase(3);
			//res += d[remainings.size()][length];
		} else if (digits[i] == 5) {
			int size = remainings.size();

			// handle 3
			if (remainings.find(3) != remainings.end())
				res += d[size-1][length];
			else
				res += d[size][length];
			
			// handle 5
			if (remainings.find(5) != remainings.end())
				remainings.erase(5);
			//res += d[remainings.size()][length];

		} else if (digits[i] == 7) {
			int size = remainings.size();

			// handle 3
			if (remainings.find(3) != remainings.end())
				res += d[size-1][length];
			else
				res += d[size][length];

			// handle 5
			if (remainings.find(5) != remainings.end())
				res += d[size-1][length];
			else
				res += d[size][length];

			// handle 7
			if (remainings.find(7) != remainings.end())
				remainings.erase(7);
			//res += d[remainings.size()][length];

		} else {
			int size = remainings.size();

			if (digits[i] < 3) {
				;
			} else if (digits[i] < 5) {
				if (remainings.find(3) != remainings.end())
					res += d[size-1][length];
				else
					res += d[size][length];
			} else if (digits[i] < 7) {
				if (remainings.find(3) != remainings.end())
					res += d[size-1][length];
				else
					res += d[size][length];

				if (remainings.find(5) != remainings.end())
					res += d[size-1][length];
				else
					res += d[size][length];
			} else {
				if (remainings.find(3) != remainings.end()) 
					res += d[size-1][length];
				else
					res += d[size][length];

				if (remainings.find(5) != remainings.end())
					res += d[size-1][length];
				else
					res += d[size][length];

				if (remainings.find(7) != remainings.end())
					res += d[size-1][length];
				else
					res += d[size][length];
			}

			break;
		}

	}

	cout << res << "\n";

	return 0;
}

int GetOrder(int number)
{

	int count = 0;
	while (number > 0) {
		number /= 10;
		++count;
	}

	return count;
}
