#include <iostream>
using namespace std;

// http://codeforces.com/contest/1068/problem/A

int main()
{
	ios_base::sync_with_stdio(false);

	unsigned long long total_num, friend_num, curr_num, new_num;
	cin >> total_num >> friend_num >> curr_num >> new_num;	

	if (friend_num * (total_num / friend_num) < curr_num + new_num) 
		cout << -1 << endl;
	else
		cout << ((curr_num + new_num) % friend_num == 0
			   ? (curr_num + new_num) / friend_num
			   : (curr_num + new_num) / friend_num + 1) << endl;

	return 0;
}
