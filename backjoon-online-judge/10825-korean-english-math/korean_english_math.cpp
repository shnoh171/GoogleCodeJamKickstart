#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/10825

struct student {
	string name;
	int korean;
	int english;
	int mathematics;
};

bool compare(const student& a, const student& b);

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<student> cls(n);

	for (int i = 0; i < n; ++i)
		cin >> cls[i].name >> cls[i].korean >> cls[i].english >> cls[i].mathematics;

	sort(cls.begin(), cls.end(), compare);

	for (int i = 0; i < n; ++i) cout << cls[i].name << "\n";

	return 0;
}

bool compare(const student& a, const student& b) {
	if (a.korean > b.korean)
		return true;
	else if (a.korean == b.korean && a.english < b.english)
		return true;
	else if (a.korean == b.korean && a.english == b.english &&
			 a.mathematics > b.mathematics)
		return true;
	else if (a.korean == b.korean && a.english == b.english &&
			 a.mathematics == b.mathematics && a.name < b.name)
		return true;

	return false;
}
