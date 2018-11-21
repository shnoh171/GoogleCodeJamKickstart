#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/10571

struct diamond {
	double weight;
	double clarity;
};

bool IsMoreValuable(const diamond& a, const diamond& b);

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		vector<diamond> diamonds(n);
		for (int j = 0; j < n; ++j) 
			cin >> diamonds[j].weight >> diamonds[j].clarity;
		
		int d[n];
		d[0] = 1; 

		for (int j = 1; j < n; ++j) {
			d[j] = 1;
			for (int k = 0; k < j; ++k)
				if (d[k] + 1 > d[j] && IsMoreValuable(diamonds[j], diamonds[k]))
					d[j] = d[k] + 1;
		}

		cout << *max_element(d, d+n) << "\n";
	}

	return 0;
}

bool IsMoreValuable(const diamond& a, const diamond& b) {
	if (a.clarity < b.clarity && a.weight > b.weight) return true;
	return false;
}
