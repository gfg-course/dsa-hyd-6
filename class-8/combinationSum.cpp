#include<bits/stdc++.h>
using namespace std;

void getCombinationsWithSumUtil(int i, vector<int> &arr, int target, vector<int> &curr,
                                vector<vector<int>> &result) {
    
    if (target == 0) {
        result.push_back(curr);
        return;
    }
    if (i == arr.size()) {
        return;
    }

    // exclude arr[i].
    getCombinationsWithSumUtil(i + 1, arr, target, curr, result);

    // include arr[i], if possible.
    if (arr[i] <= target) {
        curr.push_back(arr[i]);
        getCombinationsWithSumUtil(i, arr, target - arr[i], curr, result);
        curr.pop_back();
    }
}

// TC: O(2 ^ (max(n, tar)))
// AS: O(max(n, tar))
vector<vector<int>> getCombinationsWithSum(vector<int> arr, int target) {
    vector<int> curr;
    vector<vector<int>> result;

    getCombinationsWithSumUtil(0, arr, target, curr, result);
    return result;
}

int main() {

    vector<vector<int>> res = getCombinationsWithSum({2, 4, 6, 8}, 8);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl; 
    }
}
