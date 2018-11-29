#include <iostream>
#include <algorithm>
using namespace std;

int GetLargestSubwire(int lower, int upper, int target_num, int wires[], int size);
int GetSubwireNumber(int length, int wires[], int size);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> k >> n;

	int wires[k];
	for (int i = 0; i < k; ++i) cin >> wires[i];

	int max_val = *max_element(wires, wires+k);
	cout << GetLargestSubwire(1, max_val, n, wires, k) << "\n";

	return 0;
}

int GetLargestSubwire(int lower, int upper, int target_num, int wires[], int size)
{
	if (lower == upper) return lower;

	int mid = upper-lower == 1 ? upper : ((long long)lower + upper)/ 2;
	if (GetSubwireNumber(mid, wires, size) < target_num) 
		return GetLargestSubwire(lower, mid-1, target_num, wires, size);
	else 
		return GetLargestSubwire(mid, upper, target_num, wires, size);
}

int GetSubwireNumber(int length, int wires[], int size)
{
	int ret = 0;
	for (int i = 0; i < size; ++i) {
		ret += wires[i] / length;
	}
	return ret;
}
