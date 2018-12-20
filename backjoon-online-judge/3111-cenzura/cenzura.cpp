//#define FILEIO
//#define WAIT
#include <iostream>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

bool PopIfExist(stack<char> &s, string word);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifdef FILEIO
	ifstream fin;
	ofstream fout;
	fin.open("test/cenzura.in.8");
	fout.open("test/res.out");
#endif	

	string a, t;
#ifdef FILEIO
	fin >> a >> t;	
#else
	cin >> a >> t;
#endif
	string a_rev = a;
	reverse(a_rev.begin(), a_rev.end());

	stack<char> left, right;

	int l = 0;
	int r = t.size() - 1;
	bool is_left = true;

	while (l <= r) {
		if (is_left) {
			left.push(t[l]);
			if (PopIfExist(left, a_rev))
				is_left = !is_left;
			++l;
		} else {
			right.push(t[r]);
			if (PopIfExist(right, a))
				is_left = !is_left;
			--r;
		}
	}

	int count = 0;
	while (!left.empty()) {
		char c = left.top();
		left.pop();
		right.push(c);
		if (count++ < a.size()) {
			if (PopIfExist(right, a))
				count = 0;
		}
	}

	if (right.empty()) return 0;

	while (!right.empty()) {
#ifdef FILEIO
		fout << right.top();
#else
		cout << right.top();
#endif
		right.pop();
	}

#ifdef FILEIO
	fout << "\n";
#else
	cout << "\n";
#endif

#ifdef WAIT
	cout << flush;
	system("pause");
#endif

	return 0;
}

bool PopIfExist(stack<char> &s, string word)
{
	if (s.size() < word.size()) return false;

	string tmp;
	for (int i = 0; i < word.size(); ++i) {
		char c = s.top();
		s.pop();
		tmp += c;
	}

	if (tmp == word) {
		return true;	
	} 

	for (int i = 0; i < word.size(); ++i) {
		s.push(tmp[word.size()-1-i]);
	}

	return false;
}
