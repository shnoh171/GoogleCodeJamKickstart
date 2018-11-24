#include <iostream>
#include <algorithm>
using namespace std;

// https://www.acmicpc.net/problem/2263

void PrintPreOrder(int in_first, int in_last, int post_first, int post_last,
				   int inorder[], int postorder[]);

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int inorder[n];
	int postorder[n];
	for (int i = 0; i < n; ++i) cin >> inorder[i];
	for (int i = 0; i < n; ++i) cin >> postorder[i];

	PrintPreOrder(0, n-1, 0, n-1, inorder, postorder);

	return 0;
}

void PrintPreOrder(int in_first, int in_last, int post_first, int post_last,
				   int inorder[], int postorder[]) {
	if (in_first > in_last) return;
	if (in_first == in_last) {
		cout << inorder[in_first] << " ";
		return;
	}

	int val = postorder[post_last];
	cout << val << " ";

	int* pivot = find(inorder + in_first, inorder + in_last, val);
	int left = pivot - (inorder + in_first);
	//int right = (inorder + in_last) - pivot;

	PrintPreOrder(in_first, in_first + left - 1, 
				  post_first, post_first + left - 1, inorder, postorder);
	PrintPreOrder(in_first + left + 1, in_last,
				  post_first + left, post_last - 1, inorder ,postorder);
}
