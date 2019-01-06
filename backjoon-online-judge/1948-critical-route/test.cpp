#include <cstdio>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout("test.txt");
	int n = 10000, m = (n - 1) / 3 * 4;
    fout << n << "\n" << m << "\n";

	for (int i = 1; i < n; i += 3)
	{
        fout << i << " " <<  i+1 << "\n";
        fout << i << " " <<  i+2 << "\n";
        fout << i+1 << " " <<  i+3 << "\n";
        fout << i+2 << " " <<  i+3 << "\n";
	}

    fout << 1 << " " << n << "\n";
}