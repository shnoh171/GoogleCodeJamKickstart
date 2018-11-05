#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

// https://www.acmicpc.net/problem/2450

int min_num_of_swap(const int& i, const int& j, const int& k, vector<int>& shapes, int shapes_info[3]);

int main()
{
	int size;
	cin >> size;

	vector<int> shapes;
	int shapes_info[4] = { 0, };

	for (int i = 0; i != size; ++i) {
		int shape;
		cin >> shape;

		shapes.push_back(shape);
		++shapes_info[shape];
	}

	int res =  min_num_of_swap(1, 2, 3, shapes, shapes_info);
	res = min(res, min_num_of_swap(1, 3, 2, shapes, shapes_info));
	res = min(res, min_num_of_swap(2, 1, 3, shapes, shapes_info));
	res = min(res, min_num_of_swap(2, 3, 1, shapes, shapes_info));
	res = min(res, min_num_of_swap(3, 1, 2, shapes, shapes_info));
	res = min(res, min_num_of_swap(3, 2, 1, shapes, shapes_info));

	cout << res << endl;

	return 0;
}

int min_num_of_swap(const int& i, const int& j, const int& k, vector<int>& shapes, int shapes_info[3]) {
	int count_j_in_i = 0, count_k_in_i = 0;
	int count_j_in_k = 0, count_k_in_j = 0;

	for (int l = 0; l < shapes_info[i]; ++l) {
		if (shapes[l] == j) ++count_j_in_i;
		if (shapes[l] == k) ++count_k_in_i;
	}

	for (int l = shapes_info[i]; l < shapes_info[i] + shapes_info[j]; ++l) {
		if (shapes[l] == k) ++count_k_in_j;
	}

	for (int l = shapes_info[i] + shapes_info[j]; l < shapes.size(); ++l) {
		if (shapes[l] == j) ++count_j_in_k;
	}
	
	return count_j_in_i + count_k_in_i + max(count_j_in_k, count_k_in_j);
}
