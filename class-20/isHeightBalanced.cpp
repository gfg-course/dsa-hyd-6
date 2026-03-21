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


int calcHeightAndCheckBalanced(Node* root, bool &res) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calcHeightAndCheckBalanced(root->left, res);
    int rightHeight = calcHeightAndCheckBalanced(root->right, res);

    if (abs(leftHeight - rightHeight) > 1) {
        res = false;
    }

    return 1 + max(leftHeight, rightHeight);
}

// TC: O(n^2)
// AS: O(H)
bool isHeightBalanced(Node* root) {
   
    bool result = true;
    int _ = calcHeightAndCheckBalanced(root, result);
    return result;
}

int main() {

}
