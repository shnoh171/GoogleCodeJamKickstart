#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://beta.atcoder.jp/contests/abc113/tasks/abc113_c

struct city {
	int input_order;
	int P;
	int Y;
	string id_first;
	string id_second;
};

bool compare_P(const city& x, const city& y);
bool compare_Y(const city& x, const city& y);
bool compare_input_order(const city& x, const city& y);

string to_string_6(int number);

int main()
{
	int N, M;
	cin >> N >> M;

	vector<city> cities;
	for (int i = 0; i < M; ++i) {
		city instance;
		instance.input_order = i;
		cin >> instance.P >> instance.Y;
		cities.push_back(instance);
	}

	sort(cities.begin(), cities.end(), compare_P);

	vector<city>::iterator it_begin, it_end;
	it_begin = cities.begin();
	it_end = cities.begin();
	do {
		++it_end;

		if ((it_end == cities.end()) || (it_begin->P != it_end->P)) {
			sort(it_begin, it_end, compare_Y);

			vector<city>::iterator it;
			for (it = it_begin; it != it_end; ++it) {
				it->id_first = to_string_6(it->P);
				it->id_second = to_string_6(distance(it_begin, it) + 1);
			}

			it_begin = it_end;
		}
	} while (it_end != cities.end());
		
	sort(cities.begin(), cities.end(), compare_input_order);

	for (int i = 0; i < cities.size(); ++i)
		cout << cities[i].id_first << cities[i].id_second << endl;

	return 0;
}


bool compare_P(const city& x, const city& y)
{
	return x.P < y.P;
}

bool compare_Y(const city& x, const city& y)
{
	return x.Y < y.Y;
}

bool compare_input_order(const city& x, const city& y)
{
	return x.input_order < y.input_order;
}

string to_string_6(int number) {
	string ret;
	int tmp = number, cnt = 0;

	if (number == 0)
		return "00000000";

	while (tmp > 0) {
		tmp = tmp / 10;
		++cnt;
	}

	ret = string(6 - cnt, '0');
	ret.append(to_string(number));

	return ret;
}
