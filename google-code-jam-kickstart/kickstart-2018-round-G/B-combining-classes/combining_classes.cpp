#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <map>
#include <iterator>

using namespace std;

// Q: https://code.google.com/codejam/contest/5374486/dashboard#s=p1
// A: https://code.google.com/codejam/contest/5374486/dashboard#s=a&a=1
// Assume dataset is in correct format

// The algorithm's time complexity is O((N * log N + Q * N).
// However, it can be improved to O((N * log N + Q * log N)) if we perform
// binary search on the last step instead of linear search.
// I missed that opportunity!

struct class_score {
	long L;
	long R;
};

struct score_bst_info {
	long left;
	long right;
	long point; // for (left == right) entry
};

struct score_rank {
	long score;
	long rank;
	long prev_density_line;
	long curr_density_point;
};

void split_to_long(const string& s, const char* delim, vector<long>& v);
ifstream& get_scores_and_questions(ifstream& infile,
		vector<class_score>& class_scores, vector<long>& K);
void construct_score_rank_table(const vector<class_score>& class_scores,
		vector<score_rank>& score_rank_table);
ofstream& calculate_and_print_answer(ofstream& outfile,
		const vector<score_rank>& score_rank_table, const vector<long>& K);

int main()
{
	//ifstream infile("dataset/test.in");
	//ofstream outfile("dataset/test.out");

	//ifstream infile("dataset/B-small-practice.in");
	//ofstream outfile("dataset/B-small-practice.out");

	ifstream infile("dataset/B-large-practice.in");
	ofstream outfile("dataset/B-large-practice.out");

	string line;
	getline(infile, line);
	int T = atoi(line.c_str());
	
	for (int i = 0; i < T; ++i) {
		vector<class_score> class_scores;
		vector<long> K;
		vector<score_rank> score_rank_table;

		outfile << "Case #" << i + 1 << ": ";

		get_scores_and_questions(infile, class_scores, K);

		/*
		for (size_t i = 0; i != class_scores.size(); ++i)
			cout << "[" << class_scores[i].L << ", " << class_scores[i].R << "]" << endl;
		*/

		construct_score_rank_table(class_scores, score_rank_table);

		/*
		for (size_t i = 0; i != score_rank_table.size(); ++i)
			cout << "score: " << score_rank_table[i].score << ", rank: "
				 << score_rank_table[i].rank << ", prev_density_line: "
				 << score_rank_table[i].prev_density_line << ", curr_density_point: "
				 << score_rank_table[i].curr_density_point << endl;
		*/

		calculate_and_print_answer(outfile, score_rank_table, K);
	}

	return 0;
}

void split_to_long(const string& s, const char* delim, vector<long>& v)
{
	char *dup = strdup(s.c_str());
	char *token = strtok(dup, delim);

	while (token != NULL) {
		v.push_back(atol(token));
		token = strtok(NULL, delim);
	}
	delete(dup);
}

ifstream& get_scores_and_questions(ifstream& infile,
		vector<class_score>& class_scores, vector<long>& K)
{
	string line;
	vector<long> l1, l2, l3, l4;
	vector<long> X, Y, Z, A, B, C, M;

	getline(infile, line);
	split_to_long(line, " ", l1);
	getline(infile, line);
	split_to_long(line, " ", l2);
	getline(infile, line);
	split_to_long(line, " ", l3);
	getline(infile, line);
	split_to_long(line, " ", l4);

	int N = l1[0], Q = l1[1];

	X.push_back(l2[0]);
	X.push_back(l2[1]);
	A.push_back(l2[2]);
	B.push_back(l2[3]);
	C.push_back(l2[4]);
	M.push_back(l2[5]);

	Y.push_back(l3[0]);
	Y.push_back(l3[1]);
	A.push_back(l3[2]);
	B.push_back(l3[3]);
	C.push_back(l3[4]);
	M.push_back(l3[5]);

	Z.push_back(l4[0]);
	Z.push_back(l4[1]);
	A.push_back(l4[2]);
	B.push_back(l4[3]);
	C.push_back(l4[4]);
	M.push_back(l4[5]);

	for (int i = 2; i < N; i++) {
		X.push_back((A[0] * X[i-1] + B[0] * X[i-2] + C[0]) % M[0]);
		Y.push_back((A[1] * Y[i-1] + B[1] * Y[i-2] + C[1]) % M[1]);
	}

	for (int i = 2; i < Q; i++) 
		Z.push_back((A[2] * Z[i-1] + B[2] * Z[i-2] + C[2]) % M[2]);

	for (int i = 0; i < N; i++) {
		class_score instance;

		instance.L = min(X[i], Y[i]) + 1;
		instance.R = max(X[i], Y[i]) + 1;
		class_scores.push_back(instance);
	}

	for (int i = 0; i < Q; i++) 
		K.push_back(Z[i] + 1);
}

void construct_score_rank_table(const vector<class_score>& class_scores,
		vector<score_rank>& score_rank_table)
{
	vector<class_score>::size_type size = class_scores.size();
	map<long, score_bst_info> score_bst;
	long curr_rank, curr_score, density_point, density_line;

	for (vector<class_score>::size_type i = 0; i != size; i++) {
		long left_val = class_scores[i].L;
		long right_val = class_scores[i].R;

		if (left_val == right_val) {
			if (score_bst.find(left_val) == score_bst.end()) {
				score_bst_info instance = {0, 0, 1};
				score_bst[left_val] = instance;
			}
			else {
				++(score_bst[left_val].point);
			}
		}
		else {
			if (score_bst.find(left_val) == score_bst.end()) {
				score_bst_info instance = {1, 0, 0};
				score_bst[left_val] = instance;
			}
			else {
				++(score_bst[left_val].left);
			}

			if (score_bst.find(right_val) == score_bst.end()) {
				score_bst_info instance = {0, 1, 0};
				score_bst[right_val] = instance;
			}
			else {
				++(score_bst[right_val].right);
			}
		}
	}

	for (map<long, score_bst_info>::const_reverse_iterator riter = score_bst.rbegin();
		 riter != score_bst.rend(); riter++) {
		score_rank instance;

		if (riter == score_bst.rbegin()) {
			instance.prev_density_line = -1; // denotes first

			curr_rank = 1;
			curr_score = riter->first;
			density_point = (riter->second).right + (riter->second).point;
			density_line = (riter->second).right;
		}
		else {
			instance.prev_density_line = density_line;

			curr_rank += density_point + density_line * (curr_score - riter->first - 1);
			curr_score = riter->first;
			density_point = density_line + (riter->second).right + (riter->second).point;
			density_line = density_line + (riter->second).right - (riter->second).left;
		}

		instance.score = curr_score;
		instance.rank = curr_rank;
		instance.curr_density_point = density_point;

		score_rank_table.push_back(instance);
	}
}

ofstream& calculate_and_print_answer(ofstream& outfile,
		const vector<score_rank>& score_rank_table, const vector<long>& K)
{
	vector<long>::size_type Q = K.size();
	long res = 0;

	for (vector<long>::size_type i = 0; i != Q; i++) {
		vector<score_rank>::size_type index = 0;
		long score;

		if (K[i] > score_rank_table[score_rank_table.size() - 1].rank
				+ score_rank_table[score_rank_table.size() - 1].curr_density_point - 1) {
			score = 0;
		}
		else if (K[i] == 1) {
			score = score_rank_table[0].score;
		}
		else {
			while (K[i] > score_rank_table[index].rank)
				index++;

			long curr_score = score_rank_table[index].score;
			long curr_rank = score_rank_table[index].rank;
			long prev_density_line = score_rank_table[index].prev_density_line;

			if (index >= score_rank_table.size())
				score = score_rank_table[score_rank_table.size() - 1].score;
			else {
				if (prev_density_line < 0) {
					score = score_rank_table[index].score;
				}
				else if (prev_density_line == 0) {
					if (K[i] == curr_rank)
						score = curr_score;
					else
						score = score_rank_table[index-1].score;
				}
				else {
					score = ((curr_rank - K[i]) % prev_density_line == 0)
						  ? curr_score + (curr_rank - K[i]) / prev_density_line
						  : curr_score + (curr_rank - K[i]) / prev_density_line + 1;
				}
			}
		}
		res += score * (i + 1);
	}

	outfile << res << endl;

	return outfile;
}
