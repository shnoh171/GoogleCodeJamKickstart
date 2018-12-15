#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool IsVowel(char c);
void PrintCandidates(int idx, int cnt_c, int cnt_v, string res, int length, vector<char> chars);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, c;
	cin >> l >> c;

	vector<char> chars(c);
	for (int i = 0; i < c; ++i) cin >> chars[i];
	sort(chars.begin(), chars.end());

	int num_v = 0;
	for (int i = 0; i < chars.size(); ++i)
		if (IsVowel(chars[i]))
			++num_v;

	PrintCandidates(0, 0, 0, "", l, chars);

	return 0;
}

bool IsVowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

void PrintCandidates(int idx, int cnt_c, int cnt_v, string res, int length, vector<char> chars)
{
	if (length == 0) {
		if (cnt_c >= 2 && cnt_v >= 1) 
			cout << res << "\n";
		return;
	}
	if (idx >= chars.size()) return;

	char curr = chars[idx];

	if (IsVowel(curr))
		PrintCandidates(idx+1, cnt_c, cnt_v+1, res+curr, length-1, chars);
	else
		PrintCandidates(idx+1, cnt_c+1, cnt_v, res+curr, length-1, chars);

	PrintCandidates(idx+1, cnt_c, cnt_v, res, length, chars);
}
