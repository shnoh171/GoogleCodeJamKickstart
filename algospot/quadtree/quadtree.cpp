#include <iostream>
#include <string>
using namespace std;

void UpsideDown(string &qtree, int start, int end);
int FindMidIndex(string &qtree, int start, int end);
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

	int mid = FindMidIndex(qtree, start, end);
	UpsideDown(qtree, start, mid - 1);
	UpsideDown(qtree, mid, end);

	Swap(qtree, start, mid - 1, end);
}

int FindMidIndex(string &qtree, int start, int end) {
	int depth = 0;
	int count = 0;
	int ret = start + 1;
	while (depth == 0 && count == 3) {

	}
}

void Swap(string &qtree, int start, int mid, int end) {

}