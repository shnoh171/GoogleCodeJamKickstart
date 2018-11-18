#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/1991

void preorder(int node, int tree[][2]);
void inorder(int node, int tree[][2]);
void postorder(int node, int tree[][2]);

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int tree[n][2]; // 0: left, 1: right

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			tree[i][j] = -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		char curr, left, right;
		cin >> curr >> left >> right;
		if (left != '.') tree[curr-'A'][0] = left-'A';
		if (right != '.') tree[curr-'A'][1] = right-'A';
	}

	preorder(0, tree);
	cout << "\n";

	inorder(0, tree);
	cout << "\n";

	postorder(0, tree);
	cout << "\n";

	return 0;
}

void preorder(int node, int tree[][2]) {
	int left = tree[node][0];
	int right = tree[node][1];

	cout << (char)('A'+node);
	if (left != -1) preorder(left, tree);
	if (right != -1) preorder(right, tree);
}

void inorder(int node, int tree[][2]) {
	int left = tree[node][0];
	int right = tree[node][1];

	if (left != -1) inorder(left, tree);
	cout << (char)('A'+node);
	if (right != -1) inorder(right, tree);
}

void postorder(int node, int tree[][2]) {
	int left = tree[node][0];
	int right = tree[node][1];

	if (left != -1) postorder(left, tree);
	if (right != -1) postorder(right, tree);
	cout << (char)('A'+node);
}
