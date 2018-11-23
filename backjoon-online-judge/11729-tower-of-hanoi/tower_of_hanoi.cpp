#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/11729

int NumberOfMove(int n);
void PrintMoves(int src, int des, int height);
void PrintMove(int src, int des);

int main()
{
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << NumberOfMove(n) << "\n";
	PrintMoves(1, 3, n);

	return 0;
}

int NumberOfMove(int n) 
{
	if (n == 1) 
		return 1;
	else
		return 2 * NumberOfMove(n-1) + 1;
}

void PrintMoves(int src, int des, int height) 
{
	if (height == 1) {
		PrintMove(src, des);
	} else {
		int tgt = 6 - src - des;
		PrintMoves(src, tgt, height-1);
		PrintMove(src, des);
		PrintMoves(tgt, des, height-1);
	}
}

void PrintMove(int src, int des) 
{
	cout << src << " " << des << "\n";
}
