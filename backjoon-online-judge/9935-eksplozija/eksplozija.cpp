#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Note that the order of explosion does not matter.

void PrintNotEmptyStack(stack<pair<char, int>> &s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string text, explosion;
	cin >> text >> explosion;

	stack<pair<char, int>> s;
	for (int i = 0; i < text.size(); ++i) {
		if (s.empty() || s.top().second == -1) {
			if (text[i] == explosion[0])
				s.push(pair<char, int>(text[i], 0));
			else
				s.push(pair<char, int>(text[i], -1));
		}
		else {
			int prev = s.top().second;
			if (text[i] == explosion[prev+1])
				s.push(pair<char, int>(text[i], prev + 1));
			else if (text[i] == explosion[0])
				s.push(pair<char, int>(text[i], 0));
			else
				s.push(pair<char, int>(text[i], -1));
		}

		if (s.top().second == explosion.size() - 1) {
			for (int j = 0; j < explosion.size(); ++j)
				s.pop();
		}
	}

	if (s.empty()) {
		cout << "FRULA\n";
	}
	else {
		PrintNotEmptyStack(s);
		cout << "\n";
	}

	return 0;
}

void PrintNotEmptyStack(stack<pair<char, int>> &s)
{
	if (s.empty()) return;

	char c = s.top().first;
	s.pop();
	PrintNotEmptyStack(s);
	cout << c;

	return;
}
