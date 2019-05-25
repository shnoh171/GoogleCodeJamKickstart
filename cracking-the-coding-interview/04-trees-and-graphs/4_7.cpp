// a, b, c, d                         N
// (a, b), (b, c), (c, d)             D <= O(N^2)
// a, b, c, d

// Hash table - c->b
// Map -  
// #

// Incomplete

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

char FindZeroElement(map<char, int> counts) {

}

string FindValidSequence(vector<char> elements, vector<pair<char, char>> dependencies) {
    string ret;
    ret.reserve(elements.size());

    unordered_map<char, vector<char>> ht;
    for (auto dependency : dependencies) {
        ht[dependency.first].push_back(dependency.second);
    }

    map<char, int> counts;
    for (auto element : elements) {
        counts[element] = 0;
    }
    for (auto dependency : dependencies) {
        ++counts[dependency.second];
    }

    for (int i = 0; i < elements.size(); ++i) {
        char curr = FindZeroElement(counts);
        if (curr == '#') {
            return "";
        } else {
            ret += curr;
            for (auto element : ht[curr]) {
                --counts[element];
            }
            counts.erase(curr);
        }
    }
    return ret;
}