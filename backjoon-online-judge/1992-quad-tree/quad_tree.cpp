#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/1992

string QuadTree(vector<vector<int> > image, int y, int x, int size);

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int> > image(n, vector<int>(n));

	for (int i = 0 ; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) {
			image[i][j] = s[j] - '0';
		}
	}

	string res = QuadTree(image, 0, 0, n);

	cout << res << "\n";

	return 0;
}

string QuadTree(vector<vector<int> > image, int y, int x, int size) {
	if (size == 1) {
		if (image[y][x] == 0) return "0";
		else return "1";
	}

	string sub_res[4];
	sub_res[0] = QuadTree(image, y, x, size/2);
	sub_res[1] = QuadTree(image, y, x + size/2, size/2);
	sub_res[2] = QuadTree(image, y + size/2, x, size/2);
	sub_res[3] = QuadTree(image, y + size/2, x + size/2, size/2);

	if (sub_res[0] == "0" && sub_res[1] == "0" &&
		sub_res[2] == "0" && sub_res[3] == "0")
		return "0";

	if (sub_res[0] == "1" && sub_res[1] == "1" &&
		sub_res[2] == "1" && sub_res[3] == "1")
		return "1";

	string res;
	res += "(";
	for (int i = 0; i < 4; ++i)
		res += sub_res[i];
	res += ")";
	
	return res;
}
