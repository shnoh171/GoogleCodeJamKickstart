#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string ConvertToString(char* array, int size);

int main() {
	/* Convert character array to string */
	char a[] = { 'a', 'p', 'p', 'l', 'e' };

	string s1(a);

	string s2;
	s2 = a;

	cout << s1 << endl;
	cout << s2 << endl;

	/* Convert string to character array */
	string s = "apple";
	int size = s.length();

	char c1[size+1];
	strcpy(c1, s.c_str());

	for (int i = 0; i < size; ++i) cout << c1[i];
	cout << endl;

	return 0;
}
