#include <iostream>
#include <string>
#include <stack>
using namespace std;

// https://www.acmicpc.net/problem/10799

int main()
{
	typedef string::size_type str_sz;
	stack<str_sz> lparens;
	int count = 0;

	string input;
	cin >> input;

	for (str_sz i = 0; i != input.size(); ++i) {
		if (input[i] == '(') {
			lparens.push(i);
		} else {
			str_sz lpos = lparens.top();
			lparens.pop();
			if (lpos == i - 1)
				count = count + lparens.size();
			else
				++count;
		}
	}

	cout << count << endl;

	return 0;
}
