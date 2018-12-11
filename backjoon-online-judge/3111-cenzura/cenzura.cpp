#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void PopIfExist(stack<char> &s, string word);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> e;
	cout << e.max_size() << endl;

	string a, t;
	cin >> a >> t;
	string a_rev = a;
	reverse(a_rev.begin(), a_rev.end());

	stack<char> left, right;

	int l = 0;
	int r = t.size() - 1;
	bool is_left = true;

	while (l <= r) {
		if (is_left) {
			left.push(t[l]);
			PopIfExist(left, a_rev);
			++l;
		} else {
			right.push(t[r]);
			PopIfExist(right, a);
			--r;
		}
		is_left = !is_left;
	}

	int count = 0;
	while (!left.empty()) {
		char c = left.top();
		left.pop();
		right.push(c);
		if (count++ < a.size())
			PopIfExist(right, a);
	}

	if (right.empty()) return 0;

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	cout << "\n";

	return 0;
}

void PopIfExist(stack<char> &s, string word)
{
	if (s.size() < word.size()) return;

	string tmp;
	for (int i = 0; i < word.size(); ++i) {
		char c = s.top();
		s.pop();
		tmp += c;
	}

	if (tmp == word) return;

	for (int i = 0; i < word.size(); ++i) {
		s.push(tmp[word.size()-1-i]);
	}
}
