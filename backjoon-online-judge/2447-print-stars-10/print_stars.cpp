#include <iostream>
#include <vector>
using namespace std;

// https://www.acmicpc.net/problem/2447

bool IsRange(int y, int x, int size);
void EmptyStars(int n, vector<vector<bool> >& stars);
void BuildStars(int y, int x, int size, vector<vector<bool> >& stars);
void PrintStars(int n, vector<vector<bool> >& stars);

const int dy[8] = { 0, 0, 0, 1, 1, 2, 2, 2 };
const int dx[8] = { 0, 1, 2, 0, 2, 0, 1, 2 };

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<bool> > stars(n, vector<bool>(n));

	EmptyStars(n, stars);
	BuildStars(0, 0, n, stars);
	PrintStars(n, stars);

	return 0;
}

bool IsRange(int y, int x, int size)
{
	return y >= 0 && y < size && x >= 0 && x < size;
}

void EmptyStars(int n, vector<vector<bool> >& stars)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			stars[i][j] = false;
}

void BuildStars(int y, int x, int size, vector<vector<bool> >& stars)
{
	if (!IsRange(y, x, stars.size())) return;
	if (size == 1) {
		stars[y][x] = true;
		return;
	}

	for (int i = 0; i < 8; ++i) {
		int next_y = y + dy[i]*(size/3);
		int next_x = x + dx[i]*(size/3);

		BuildStars(next_y, next_x, size/3, stars);
	}
}

void PrintStars(int n, vector<vector<bool> >& stars)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (stars[i][j] ? '*' : ' ');
		}
		cout << "\n";
	}
}
