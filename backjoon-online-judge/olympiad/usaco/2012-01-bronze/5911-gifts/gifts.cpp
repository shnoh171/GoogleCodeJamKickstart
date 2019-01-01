#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct cost {
	int price;
	int shipping;
	int total;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, b;
	cin >> n >> b;

	vector<cost> request(n);
	for (int i = 0; i < n; ++i) {
		cin >> request[i].price;
		cin >> request[i].shipping;
		request[i].total = request[i].price + request[i].shipping;
	}

	sort(request.begin(), request.end(), [](cost a, cost b) { return a.total < b.total; });
	
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (b - request[i].total < 0)
			break;
		b -= request[i].total;
		++count;
	}

	for (int i = count; i < n; ++i) {
		if (request[i].price / 2 + request[i].shipping <= b) {
			cout << count + 1 << "\n";
			return 0;
		}
	}

	cout << count << "\n";

	return 0;
}