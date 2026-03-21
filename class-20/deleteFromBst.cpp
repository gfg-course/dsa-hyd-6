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

int getMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// TC: O(2*H)
// AS: O(H)
Node* deleteFromBst(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (val > root->data) {
        root->right = deleteFromBst(root->right, val);
    } else if (val < root->data) {
        root->left = deleteFromBst(root->left, val);
    } else {
        // int childCount = 0;
        // if (root->left != NULL) {
        //     childCount++;
        // } 
        // if (root->right != NULL) {
        //     childCount++;
        // }

        // if (childCount == 0) {
        //     return NULL;
        // }
        // if (childCount == 1) {
        //     if (root->left != NULL) {
        //         return root->left;
        //     }
        //     return root->right;
        // }

        if (root->left == NULL) {
            return root->right;
        }
        if (root->right == NULL) {
            return root->left;
        }

        int inorderSucc = getMin(root->right);
        root->data = inorderSucc;
        root->right = deleteFromBst(root->right, inorderSucc);
    }
    return root;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(9);
    root->right = new Node(11);
    root->right->right = new Node(12);

    root = insertInBst(root, 7);

}
 