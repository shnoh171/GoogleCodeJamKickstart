#include <iostream>
#include <stack>
#include <string>
using namespace std;

// https://www.acmicpc.net/problem/9012

// Not good coding style
istream& is_correct_paren(istream& in, ostream& out);

int main()
{
	ios_base::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i != num; ++i)
		is_correct_paren(cin, cout);

	return 0;
}

istream& is_correct_paren(istream& in, ostream& out) {
	string s;
	stack<int> st;

	cin >> s;
	string::size_type size = s.size();

	for (string::size_type i = 0; i != size; ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else { 
			if (st.empty()) {
				out << "NO" << endl;
				return in;
			} else {
				st.pop();
			}
		}
	}

	if (st.empty())
		out << "YES" << endl;
	else
		out << "NO" << endl;

	return in;
}
