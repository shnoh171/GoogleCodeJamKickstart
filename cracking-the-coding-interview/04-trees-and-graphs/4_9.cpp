//       4
//    2     6
//   1 3   5 7


//   2
//  1 3

// []
// [ptr 2]

// [2]
// [ptr 1, ptr 3]

// Case: ptr 1 selected
// [2, 1]
// [ptr 3]

// [2, 1, 3]
// []

// Case: ptr 3 selected
// [2, 3]
// [ptr 1]

// [2, 3, 1]
// []


// 4
// 2 or 6  -> 2

// [4, 2]
// [pointer to 1, pointer to 3, pointer to 6]

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int v) { value = v; left = right = NULL; }
};

void _GetAllPossibleSequences(vector<vector<int>>& sequences, vector<int> curr_seq, unordered_set<BSTNode*> ptrs) {
    if (ptrs.empty()) {
        sequences.push_back(curr_seq);
        return;
    }

    for (auto ptr : ptrs) {
        unordered_set<BSTNode*> next_ptrs = ptrs;

        curr_seq.push_back(ptr->value);
        if (ptr->left != NULL) ptrs.insert(ptr->left);
        if (ptr->right != NULL) ptrs.insert(ptr->right);
        ptrs.erase(ptr);

        _GetAllPossibleSequences(sequences, curr_seq, ptrs);

        curr_seq.pop_back();
        if (ptr->left != NULL) ptrs.erase(ptr->left);
        if (ptr->right != NULL) ptrs.erase(ptr->right);
        ptrs.insert(ptr);
    }
}

vector<vector<int>> GetAllPossibleSequences(BSTNode* root) {
    vector<vector<int>> ret;
    vector<int> curr_seq;
    unordered_set<BSTNode*> next_ptrs;
    next_ptrs.insert(root);
    _GetAllPossibleSequences(ret, curr_seq, next_ptrs);
    return ret;
}