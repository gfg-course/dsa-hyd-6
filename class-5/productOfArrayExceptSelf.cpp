#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(n)
vector<int> productExceptSelf(vector<int> arr) {

    int n = arr.size();
    vector<int> suffProd(n);
    vector<int> ans(n);

    suffProd[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffProd[i] = suffProd[i + 1] * arr[i + 1];
    }

    int prefProd = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefProd * suffProd[i];
        prefProd = prefProd * arr[i];
    }
    return ans;
}

int main() {

    vector<int> result = productExceptSelf({-1, 1, 0, -3, 3});
    for (int i : result) {
        cout << i << " ";
    }
}
