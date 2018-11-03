#include <bits/stdc++.h>

using namespace std;

// Simple implementation problem

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = 0, day;
	int count = 256;
	string ret;

	if (year < 1918) {
		if (year % 4 == 0) ++days[1];
	}
	else if (year > 1918) {
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) ++days[1];
	}
	else {
		days[1] -= 13;
	}

	while (count - days[month] > 0) {
		count -= days[month];
		month++;
	}
	month++;
	day = count;

	if (day < 10) ret += "0" + to_string(day);
	else ret += to_string(day);

	if (month < 10) ret += (".0" + to_string(month));
	else ret += ("." + to_string(month));

	ret += ("." + to_string(year));

	return ret;
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	string year_temp;
	getline(cin, year_temp);

	int year = stoi(ltrim(rtrim(year_temp)));

	string result = dayOfProgrammer(year);

	//fout << result << "\n";
	cout << result << "\n";

	//fout.close();

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

