#include<bits/stdc++.h>
using namespace std;

// TC: O(n*W)
// AS: O(n*W)
int getMaxValue(vector<int> vals, vector<int> wts, int W) {

    int n = vals.size();
    
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));
    
    // Base conditions.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= W; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // skip.
            dp[i][j] = dp[i - 1][j];
            
            // take, if possible.
            if (wts[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], vals[i - 1] + dp[i - 1][j - wts[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120}, {10, 20, 50}, 50) << endl;
}
