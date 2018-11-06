#include <bits/stdc++.h>

using namespace std;

// All codes except the function pickingNumbers() is given

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
	typedef vector<int>::size_type vec_sz;
	vec_sz size = a.size();
	sort(a.begin(), a.end());
	vec_sz ret = 0;

	vec_sz prev_begin = -1, curr_begin = 0;

	for (vec_sz i = 0; i != size; ++i) {
		if (a[i] != a[curr_begin]) {
			if (prev_begin < 0) {
				ret = i;
			} else if (a[curr_begin] == a[prev_begin] + 1) {
				ret = max(ret, i - prev_begin);
			} else {
				ret = max(ret, i - curr_begin);
			}
			prev_begin = curr_begin;
			curr_begin = i;
		}
	}

	if (a[curr_begin] == a[prev_begin] + 1) {
		ret = max(ret, size - prev_begin);
	} else {
		ret = max(ret, size - curr_begin);
	}

	return (int)ret;
}

int main()
{
	string n_temp;
	getline(cin, n_temp);

	int n = stoi(ltrim(rtrim(n_temp)));

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split(rtrim(a_temp_temp));

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		int a_item = stoi(a_temp[i]);

		a[i] = a_item;
	}

	int result = pickingNumbers(a);

	cout << result << "\n";

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
			s.begin(),
			find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
		   );

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
			find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
			s.end()
		   );

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}

