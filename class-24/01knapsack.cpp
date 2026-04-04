#include<bits/stdc++.h>
using namespace std;

int getMaxValueUtil(int i, vector<int> vals, vector<int> wts, int W, vector<vector<int>> &memo) {
    if (i == vals.size() || W == 0) {
        return 0;
    }
    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    // skip.
    int result = getMaxValueUtil(i + 1, vals, wts, W, memo);

    // take, if possible.
    if (wts[i] <= W) {
        result = max(result, vals[i] + getMaxValueUtil(i + 1, vals, wts, W - wts[i], memo));
    }

    memo[i][W] = result;
    return result;
}

// Plain Rec:
// TC: O(2^n)
// AS: O(n)

// DP:
// TC: O(n*W)
// AS: O(n*W)
int getMaxValue(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();

    // i: 0 ... n-1 -> n
    // W: W ... 0 -> W + 1
    vector<vector<int>> memo(n, vector<int> (W + 1, -1));

    return getMaxValueUtil(0, vals, wts, W, memo);
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}
