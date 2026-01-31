#include<bits/stdc++.h>
using namespace std;

// TC: O(A + B + C)
// AS: O(1)
vector<int> merge3SortedArrays(vector<int> A, vector<int> B, vector<int> C) {

    int i = 0, j = 0, k = 0;
    vector<int> result;

    while (i < A.size() || j < B.size() || k < C.size()) {
        int a = i < A.size() ? A[i] : INT_MAX;
        int b = j < B.size() ? B[j] : INT_MAX;
        int c = k < C.size() ? C[k] : INT_MAX;

        if (a == min({a, b, c})) {
            result.push_back(a);
            i++;
        } else if (b == min({a, b, c})) {
            result.push_back(b);
            j++;
        } else {
            result.push_back(c);
            k++;
        }
    }
    return result;
}

int main() {

    vector<int> result = merge3SortedArrays({1, 2, 5, 6}, {1, 3, 6}, {8, 11});
    for (int i : result) {
        cout << i << " ";
    }
}
