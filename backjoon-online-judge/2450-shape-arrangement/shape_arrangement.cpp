#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void split_to_int(const string& s, const char* delim, vector<int>& v);

int main()
{
	string s;
	int size;
	cin >> size;

	vector<int> shapes;
	split_to_int
	return 0;
}

void split_to_int(const string& s, const char* delim, vector<int>& v)
{
	char *dup = strdup(s.c_str());
	char *token = strtok(dup, delim);

	while (token != NULL) {
		v.push_back(atoi(token));
		token = strtok(NULL, delim);
	}
	delete(dup);
}
