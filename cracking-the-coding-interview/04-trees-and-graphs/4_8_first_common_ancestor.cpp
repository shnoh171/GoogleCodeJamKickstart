#include <iostream>
using namespace std;

// Not tested

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) { value = v; }
};

void _FindFirstCommonAncestor(Node* curr, Node* node1, Node* node2, Node*& cand1, Node*& cand2) {
    if (curr == NULL) return;
    if (cand1 == cand2) return;

    _FindFirstCommonAncestor(curr->left, node1, node2, cand1, cand2);
    _FindFirstCommonAncestor(curr->right, node1, node2, cand1, cand2);
    
    if (cand1 == NULL) {
        if (curr == node1 || curr == node2) {
            cand1 = curr;
        }
    } else {
        if (curr->left == cand1) cand1 = curr->left;
        else if (curr->right == cand1) cand1 = curr->right;

        if (cand2 == NULL) {
            if (curr == node1 || curr == node2) {
                cand2 = curr;
            }
        } else {
            if (curr->left == cand2) cand2 = curr->left;
            else if (curr->right == cand2) cand2 = curr->right;
        }
    }   
}

Node* FindFirstCommonAncestor(Node* root, Node* node1, Node* node2) {
    Node* cand1 = NULL;
    Node* cand2 = NULL;
    _FindFirstCommonAncestor(root, node1, node2, cand1, cand2);
    return cand1;
}