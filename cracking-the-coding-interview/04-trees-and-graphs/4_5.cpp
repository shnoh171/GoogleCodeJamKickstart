#include <iostream>
using namespace std;

const int ninf = -1000000000;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) { value = v; left = right = NULL; }
};

bool _IsBST(TreeNode* node, int& curr_value) {
    if (node == NULL) return true;

    bool ret = true;

    ret = ret && _IsBST(node->left, curr_value);
    if (curr_value > node->value) {
        ret = false;
    }
    curr_value = node->value;
    ret = ret && _IsBST(node->right, curr_value);

    return ret;
}

bool IsBST(TreeNode* root) {
    int value = ninf;
    return _IsBST(root, value);
}