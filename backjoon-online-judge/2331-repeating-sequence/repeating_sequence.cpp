#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// https://www.acmicpc.net/problem/2331

int next_number(int a, int p);

int main()
{
	ios_base::sync_with_stdio(false);

	int a, p;
	cin >> a >> p;

	map<int, int> sequences;

	int next = a;
	while (sequences.find(next) == sequences.end()) {
		sequences[next] = next_number(next, p);
		next = next_number(next, p);
	}

	int count = 0;

	while (a != next) {
		a = sequences[a];
		++count;
	}

	cout << count << "\n";

	return 0;
}

int next_number(int a, int p) {
	if (a == 0) return 0;
	else return pow(a%10, p) + next_number(a/10, p);
}
