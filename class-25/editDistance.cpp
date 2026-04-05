#include<bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// AS: O(m)
int editDistanceBottomUp(string A, string B) {
    int n = A.length();
    int m = B.length();

    // vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // for (int i = 0; i <= n; i++) {
    //     dp[i][0] = i;
    // }

    vector<int> prevRow(m + 1);
    for (int j = 0; j <= m; j++) {
        prevRow[j] = j;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> currRow(m + 1);
        currRow[0] = i;
        for (int j = 1; j <= m; j++) {
            // dp[i][j];
            if (A[i - 1] == B[j - 1]) {
                // dp[i][j] = dp[i - 1][j - 1];
                currRow[j] = prevRow[j - 1];
            } else {
                // dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                currRow[j] = 1 + min({prevRow[j], currRow[j - 1], prevRow[j - 1]});
            }
        }
        prevRow = currRow;
    }

    // return dp[n][m];
    return prevRow[m];
}

// Returns edit distance to convert A[i ... n-1] to B[j ... m-1]
int editDistanceUtil(int i, int j, string &A, string &B, vector<vector<int>> &memo) {
    // Do B.length() - j insertions.
    if (i == A.length()) {
        return B.length() - j;
    }

    // Do A.length() - i deletions.
    if (j == B.length()) {
        return A.length() - i;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (A[i] == B[j]) {
        memo[i][j] = editDistanceUtil(i + 1, j + 1, A, B, memo);
        return memo[i][j];
    }

    int insert = editDistanceUtil(i, j + 1, A, B, memo);
    int del = editDistanceUtil(i + 1, j, A, B, memo);
    int replace = editDistanceUtil(i + 1, j + 1, A, B, memo);

    memo[i][j] = 1 + min({insert, del, replace});
    return memo[i][j];
}

// Plain Rec:
// TC: O(3^max(n, m))
// AS: O(max(n, m))

// DP:
// TC: O(n*m)
// AS: O(n*m)
int editDistance(string A, string B) {
    int n = A.length();
    int m = B.length();

    vector<vector<int>> memo(n, vector<int> (m, -1));
    return editDistanceUtil(0, 0, A, B, memo);
}

int main() {

    cout << editDistanceBottomUp("Anshuman", "Antihuman") << endl;
}
