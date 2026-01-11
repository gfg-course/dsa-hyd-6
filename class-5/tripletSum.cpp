#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2)
// AS: O(1)
bool tripletWithGivenSum(vector<int> arr, int target) {

    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            if (arr[j] + arr[k] == target - arr[i]) {
                return true;
            }
            if (arr[j] + arr[k] > target - arr[i]) {
                k--;
            } else {
                j++;
            }
        }
    }

    return false;
}

int main() {

    cout << tripletWithGivenSum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << tripletWithGivenSum({1, 4, 45, 6, 10, 8}, 30) << endl;
}
