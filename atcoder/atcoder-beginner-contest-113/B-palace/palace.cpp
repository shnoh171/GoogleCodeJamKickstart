#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// https://beta.atcoder.jp/contests/abc113/tasks/abc113_b

int main()
{
	int N, T, A;
	cin >> N >> T >> A;

	vector<int> H;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		H.push_back(tmp);
	}

	double avg_temp = T - H[0] * 0.006;
	int index = 0;

	for (int i = 1; i < H.size(); ++i) {
		double curr_avg_temp = T - H[i] * 0.006;
		if (fabs(avg_temp - A) > fabs(curr_avg_temp - A)) {
			avg_temp = curr_avg_temp;
			index = i;
		}
	}

	cout << index + 1 << endl;

	return 0;
}
