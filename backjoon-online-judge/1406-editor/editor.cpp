#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<char> left, right;

	string s;
	cin >> s;
	int size = s.size();

	int num;
	cin >> num;

	for (int i = 0; i != size; ++i)
		left.push(s[i]);

	for (int i = 0; i != num; ++i) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		} else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		} else if (cmd == 'B') {
			if (!left.empty()) left.pop();
		} else { // cmd == 'P'
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	cout << endl;

	return 0;
}
	
