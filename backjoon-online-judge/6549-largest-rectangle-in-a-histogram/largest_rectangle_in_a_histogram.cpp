#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct element {
	int idx;
	int lidx;
	int height;
	
	element(int i, int l, int h) { idx = i; lidx = l; height = h; };
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		vector<int> h(n);
		vector<int> left(n), right(n);
		for (int i = 0; i < n; ++i) cin >> h[i];

		stack<element> s;
		for (int i = 0; i < n; ++i) {
			int curr_height = h[i];

			while (!s.empty() && s.top().height > curr_height) {
				right[s.top().idx] = i - 1;
				s.pop();				
			}

			if (s.empty())
				left[i] = 0;
			else if (s.top().height == curr_height)
				left[i] = s.top().lidx;
			else
				left[i] = s.top().idx + 1;

			if (!s.empty() && s.top().height == curr_height)
				s.push(element(i, s.top().lidx, curr_height));
			else
				s.push(element(i, i, curr_height));
		}

		while (!s.empty()) {
			right[s.top().idx] = n - 1;
			s.pop();
		}

		long long res = 0;
		for (int i = 0; i < n; ++i)
			res = max(res, (long long) h[i] * (right[i] - left[i] + 1));
		cout << res << "\n";
	}


	return 0;
}
