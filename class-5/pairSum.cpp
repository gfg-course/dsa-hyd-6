#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// AS: O(1)
bool pairWithGivenSum(vector<int> arr, int target) {

    int i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i] + arr[j] == target) {
            return true;
        }
        if (arr[i] + arr[j] > target) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    cout << pairWithGivenSum({1, 2, 5, 6, 10}, 8) << endl;
    cout << pairWithGivenSum({1, 2, 5, 6, 10}, 9) << endl;
    cout << pairWithGivenSum({1, 2, 5, 6, 10}, 10) << endl;
    cout << pairWithGivenSum({1, 2, 5, 5, 6, 10}, 10) << endl;
}
