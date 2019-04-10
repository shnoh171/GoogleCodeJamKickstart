#include <iostream>
#include <vector>
using namespace std;

int GetMaxSize(const vector<int> &fence, int start, int end);
int GetMaxSizeContainingMid(const vector<int> &fence, int start, int mid, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
		int n;
		cin >> n;
		vector<int> fence(n);
		for (int i = 0; i < n; ++i) {
			cin >> fence[i];
		}
		cout << GetMaxSize(fence, 0, n-1) << "\n";
	}

	return 0;
}

int GetMaxSize(const vector<int> &fence, int start, int end) {
	if (start == end) return fence[start];

	int mid = (start + end) / 2;
	int size = max(GetMaxSize(fence, start, mid), GetMaxSize(fence, mid+1, end));
	size = max(size, GetMaxSizeContainingMid(fence, start, mid, end));

	return size;
}

int GetMaxSizeContainingMid(const vector<int> &fence, int start, int mid, int end) {
	int front = mid;
	int back = mid + 1;
	int height = min(fence[front], fence[back]);
	int max_size = height * 2;

	while (front >= start || back <= end) {
		if (front < start) height = fence[back];
		else if (back > end) height = fence[front];
		else height = max(fence[back], fence[front]);
		
		while (front >= start && fence[front] >= height) --front;
		while (back <= end && fence[back] >= height) ++back;

		max_size = max(max_size, (back-front-1) * height);
	}

	return max_size;
}