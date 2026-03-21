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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


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

Node* constructBstUtil(vector<int> &arr, int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node* root = new Node(arr[mid]);

    root->left = constructBstUtil(arr, low, mid - 1);
    root->right = constructBstUtil(arr, mid + 1, high);

    return root;
}

// TC: O(n)
// AS: O(log(n))
Node* sortedArrayToHtBalancedBst(vector<int> arr) {
    return constructBstUtil(arr, 0, arr.size() - 1);
}

int main() {
    Node* root = sortedArrayToHtBalancedBst({1, 2, 3, 4, 5, 6, 7});

    inorder(root);

    cout << endl;

    cout << isHeightBalanced(root);
}
