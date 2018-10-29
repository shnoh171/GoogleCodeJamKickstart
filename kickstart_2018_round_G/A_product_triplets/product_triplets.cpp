#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdlib>
#include <unordered_map>

using namespace std;

// This algorithm's time compleixity is O(N^2) which is same as the given answer on
// 'https://codejam.withgoogle.com/codejam/contest/5374486/dashboard#s=a&a=0',
// but it takes about 10 min.
// More optimization is needed to pass the given time limit (8 min).

void split(const string& s, const char* delim, vector<string>& v);
void split_to_long(const string& s, const char* delim, vector<long>& v);

int main()
{
	ifstream infile("dataset/A-small-practice.in");
	ofstream outfile("dataset/A-small-practice.out");

	//ifstream infile("dataset/A-large-practice.in");
	//ofstream outfile("dataset/A-large-practice.out");
	
	string s;
	getline(infile, s);
	int T = atoi(s.c_str());

	for (int i = 0; i != T; ++i) {
		vector<long> v;
		typedef vector<long>::size_type vec_sz;
		unordered_map<long, vector<long>> hash_map;

		long triple_dup = 0, double_dup = 0, no_dup = 0;
		
		getline(infile, s);
		int N = atoi(s.c_str());

		getline(infile, s);
		split_to_long(s, " ", v);

		for (vec_sz i = 0; i != N; ++i) {
			for (vec_sz j = i + 1; j != N; ++j) {
				hash_map[v[i] * v[j]].push_back(i);
				hash_map[v[i] * v[j]].push_back(j);
			}
		}

		// Time complexity: O(# of entries in hash_map) = O(N^2)
		unordered_map<long, vector<long>> answer;
		for (vec_sz i = 0; i != N; ++i) {
			unordered_map<long, vector<long>>::const_iterator it = hash_map.find(v[i]);
			if (it != hash_map.end()) {
				vec_sz curr = 0;
				vec_sz size = (it->second).size();

				if (answer.find(v[i]) == answer.end()) {
					long local_triple_dup = 0, local_double_dup = 0, local_no_dup = 0;

					while (curr != size) {
						vec_sz j = (it->second)[curr + 0];
						vec_sz k = (it->second)[curr + 1];

						if (i != j && i != k) {
							if (v[i] == 1 && v[j] == 1 && v[k] == 1) local_triple_dup++;
							else if (v[i] == 0 && v[j] == 0 && v[k] == 0) local_triple_dup++;
							else if (v[i] == 1 && v[j] != 1 && v[k] != 1) local_double_dup++;
							else if (v[i] != 1 && v[j] == 1 && v[k] != 1) local_double_dup++;
							else if (v[i] != 1 && v[j] != 1 && v[k] == 1) local_double_dup++;
							else if (v[i] == 0 && v[j] == 0 && v[k] != 0) local_double_dup++;
							else if (v[i] == 0 && v[j] != 0 && v[k] == 0) local_double_dup++;
							else if (v[i] != 0 && v[j] == 0 && v[k] == 0) local_double_dup++;
							else local_no_dup++;
						}

						curr += 2;
					}

					answer[v[i]].push_back(local_triple_dup);
					answer[v[i]].push_back(local_double_dup);
					answer[v[i]].push_back(local_no_dup);

					triple_dup += local_triple_dup;
					double_dup += local_double_dup;
					no_dup += local_no_dup;
				}
				else {
					triple_dup += answer[v[i]][0];
					double_dup += answer[v[i]][1];
					no_dup += answer[v[i]][2];
				}
			}
		}
		outfile << "Case #" << i + 1 << ": " << triple_dup / 3 + double_dup / 2 + no_dup << endl;
	}

	return 0;
}

void split(const string& s, const char* delim, vector<string>& v)
{
	char *dup = strdup(s.c_str());
	char *token = strtok(dup, delim);

	while (token != NULL) {
		v.push_back(string(token));
		token = strtok(NULL, delim);
	}
	delete(dup);
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
