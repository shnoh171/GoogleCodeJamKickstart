#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> one;
	vector<pair<int, int> > many;

	cin >> n;
	for (int i = 1; i < n+1; ++i) {
		int edge;
		cin >> edge;

		if (edge == 1) {
			one.push_back(i);
		} else {
			many.push_back(make_pair(i, edge));
		}
	}
	
	if (many.size() == 0) {
		cout << "NO\n";
		return 0;
	}

	if (many.size() == 1) {
		if (many[0].second >= one.size()) {
			cout << "YES " << "2\n";
			cout << one.size() << "\n";
			for (int i = 0; i < one.size(); ++i)
				cout << many[0].first << " " << one[i] << "\n";
		} else {
			cout << "NO\n";
		}
		return 0;
	}

	int available = 0;
	for (int i = 0; i < many.size(); ++i)
		available += many[i].second - 2;
	available += 2;
	
	if (one.size() == 0) {
		cout << "YES " << many.size()-1 << "\n";
		cout << many.size()-1 << "\n";
		for (int i = 1; i < many.size(); ++i)
			cout << many[i-1].first << " " << many[i].first << "\n";

		return 0;
	}

	if (available < one.size()) {
		cout << "NO\n";
		return 0;
	}

	if (one.size() == 1) {
		cout << "YES " << many.size() << "\n";
		cout << many.size() << "\n";
		
		cout << one[0] << " " << many[0].first << "\n";

		for (int i = 1; i < many.size(); ++i)
			cout << many[i-1].first << " " << many[i].first << "\n";

		return 0;
	}

	cout << "YES " << many.size() + 1 << "\n";
	cout << n-1 << "\n";
	
	cout << one[0] << " " << many[0].first << "\n";
	cout << one[1] << " " << many[many.size()-1].first << "\n";
	for (int i = 1; i < many.size(); ++i)
		cout << many[i-1].first << " " << many[i].first << "\n";

	int j = 0;
	for (int i = 2; i < one.size(); ++i) {
		if (many[j].second == 2) ++j;

		--(many[j].second);
		cout << one[i] << " " << many[j].first << "\n";
	}


	return 0;
}
