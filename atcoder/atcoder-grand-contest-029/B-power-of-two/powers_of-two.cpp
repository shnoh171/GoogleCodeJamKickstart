#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool MakePair(int idx, vector<int> &cand, vector<bool> &check);
int GetNext2n(int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	vector<bool> check(n);
	for (int i = 0; i < n; ++i) check[i] = false;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (!check[i] && MakePair(i, a, check))
			++count;
	}

	cout << count << "\n";

	return 0;
}

bool MakePair(int idx, vector<int> &cand, vector<bool> &check)
{
	check[idx] = true;
	int target = GetNext2n(cand[idx]) - cand[idx];
	
	int left = idx + 1;
	int right = cand.size() - 1;
	int ans = cand.size();

	while (left <= right) {
		int mid = (left + right) / 2;
		if (cand[mid] > target || (cand[mid] == target && check[mid])) {
			left = mid + 1;
		}
		else if (cand[mid] < target || (cand[mid] == target && !check[mid])) {
			if (cand[mid] == target) {
				ans = min(ans, mid);
			}
			right = mid - 1;
		}
	}

	if (ans != cand.size()) {
		check[ans] = true;
		return true;
	}
	else {
		return false;
	}
}

int GetNext2n(int num)
{
	int ret = 1;
	while (ret <= num) ret = ret << 1;
	return ret;
}