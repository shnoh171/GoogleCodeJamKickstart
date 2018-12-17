#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, bomb;
	cin >> s >> bomb;

	queue<char> first, second;
	for (int i = 0; i < s.size(); ++i)
		first.push(s[i]);

	queue<char> &curr = first;
	queue<char> &next = second;

	int count = 1;
	while (count != 0 && curr.size() >= bomb.size()) {
		count = 0;
		string temp;

		while (!curr.empty()) {
			char c = curr.front();
			curr.pop();

			if (temp.size() < bomb.size()) {
				temp += c;
			} else if (temp == bomb) {
				temp = c;
				++count;
			} else {
				next.push(temp[0]);
				temp = temp.substr(1, temp.size()-1);
				temp += c;
			}
		}

		if (temp != bomb)
			for (int i = 0; i < temp.size(); ++i)
				next.push(temp[i]);

		swap(curr, next);
	}

	if (curr.empty())
		cout << "FRULA";

	while (!curr.empty()) {
		cout << curr.front();
		curr.pop();
	}
	cout << "\n";

	return 0;
}
