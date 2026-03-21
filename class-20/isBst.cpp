#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBst(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (root->data == value) {
        return root;
    }

    if (root->data < value) {
        root->right = insertInBst(root->right, value);
    } else {
        root->left = insertInBst(root->left, value);
    }

    return root;
}

bool isBstUtil(Node* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    return
        root->data >= min && root->data <= max &&
        isBstUtil(root->left, min, root->data - 1) &&
        isBstUtil(root->right, root->data + 1, max);
}

// TC: O(n)
// AS: O(H)
bool isBst(Node* root) {
    return isBstUtil(root, -1e9, 1e9);
}

int main() {

    Node* root = NULL;
    root = insertInBst(root, 10);
    root = insertInBst(root, 3);
    root = insertInBst(root, 12);
    root = insertInBst(root, 2);
    root = insertInBst(root, 5);
    root = insertInBst(root, 11);
    root = insertInBst(root, 50);

    cout << isBst(root) << endl;

    root->left->right->data = 11;
    cout << isBst(root) << endl;
}
 