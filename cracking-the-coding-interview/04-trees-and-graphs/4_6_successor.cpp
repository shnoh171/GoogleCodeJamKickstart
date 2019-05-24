#include <iostream>
using namespace std;

// Did not tested

struct bst_node {
    int value;
    bst_node* left;
    bst_node* right;
    bst_node* parent;
    bst_node(int v) { value = v; }
};

bool IsLeftChild(bst_node *child, bst_node *parent) {
    if (parent == NULL) return false;
    if (parent->left == child) return true;
    else return false;
}

bst_node* FindNextNode(bst_node *curr) {
    if (curr == NULL) return NULL;

    if (curr->right != NULL) {
        curr = curr-> right;
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    } else {
        while (curr->parent != NULL) {
            if (IsLeftChild(curr, curr->parent)) {
                return curr->parent;
            }
            curr = curr->parent;
        }
        return NULL;
    }
}