#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
int getMaxSumSubarray(vector<int> arr) {
    int n = arr.size();
    int maxTillHere = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        maxTillHere = max(maxTillHere + arr[i], arr[i]);
        result = max(result, maxTillHere);
    }

    return result;
}

int main() {

    cout << getMaxSumSubarray({5, -6, 3, 2, 7, -5, 8}) << endl;
    cout << getMaxSumSubarray({-1, -2, -3, -4}) << endl;
    cout << getMaxSumSubarray({1, 2, 3, 4}) << endl;
}
