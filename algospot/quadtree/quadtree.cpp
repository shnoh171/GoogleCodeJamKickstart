#include <iostream>
#include <string>
#include <stack>
using namespace std;

void UpsideDown(string &qtree, int start, int end);
int GoOneRegion(string &qtree, int start);
void Swap(string &qtree, int start, int mid, int end);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	cin >> c;

	while (c--) {
		string qtree;
		cin >> qtree;
		UpsideDown(qtree, 0, qtree.size() - 1);
		cout << qtree << "\n";
	}
	return 0;
}

void UpsideDown(string &qtree, int start, int end) {
	if (start == end) return;
	if (qtree[start] != 'x') return;

	int q1 = start + 1;
	int q2 = GoOneRegion(qtree, q1);
	int q3 = GoOneRegion(qtree, q2);
	int q4 = GoOneRegion(qtree, q3);

	UpsideDown(qtree, q1, q2 - 1);
	UpsideDown(qtree, q2, q3 - 1);
	UpsideDown(qtree, q3, q4 - 1);
	UpsideDown(qtree, q4, end);

	Swap(qtree, q1, q3, end);

	return;
}

int GoOneRegion(string &qtree, int start) {
	int cnt = 1;

	while (cnt > 0) {
		if (qtree[start++] == 'x') {
			cnt += 3;
		} else {
			--cnt;
		}
	}

	return start;
}

void Swap(string &qtree, int start, int mid, int end) {
	string temp(qtree, start, mid-start);

	for (int i = 0; i < end - mid + 1; ++i) {
		qtree[start + i] = qtree[mid + i];
	}
	
	for (int i = 0; i < temp.size(); ++i) {
		qtree[start + end - mid + 1 + i] = temp[i];
	}
}