#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/6588

int main()
{
	ios_base::sync_with_stdio(false);
	int num;
	vector<int> numbers;

	cin >> num;
	while (num != 0) {
		numbers.push_back(num);
		cin >> num;
	}

	int max = *max_element(numbers.begin(), numbers.end());

	bool is_prime[max+1];
	fill_n(is_prime, max+1, true);
	is_prime[0] = false, is_prime[1] = false;
	
	for (int i = 2; i*i < max+1; ++i) {
		if (is_prime[i] == true) {
			for (int j = i*2; j < max+1; j += i) {
				is_prime[j] = false;
			}
		}
	}

	vector<int> odd_primes;
	for (int i = 3; i < max+1; ++i) {
		if (is_prime[i] == true) odd_primes.push_back(i);
	}

	for (int i = 0; i < numbers.size(); ++i) {
		int j = 0;
		while (odd_primes[j] < numbers[i]/2 + 1) {
			if (is_prime[numbers[i] - odd_primes[j]] == true) {
				cout << numbers[i] << " = " << odd_primes[j] << " + " << numbers[i]-odd_primes[j] << "\n";
				break;
			}
			++j;
		}

		if (odd_primes[j] >= numbers[i]/2 + 1)
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}
