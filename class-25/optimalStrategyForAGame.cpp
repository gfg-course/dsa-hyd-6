#include<bits/stdc++.h>
using namespace std;

// Problem Statement: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

int getMaxScoreUtil(int i, int j, vector<int> &coins, vector<vector<int>> &memo) {
    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int option1 = coins[i] + 
        min(getMaxScoreUtil(i + 2, j, coins, memo), getMaxScoreUtil(i + 1, j - 1, coins, memo));
    
    int option2 = coins[j] + 
        min(getMaxScoreUtil(i + 1, j - 1, coins, memo), getMaxScoreUtil(i, j - 2, coins, memo));
    
    memo[i][j] = max(option1, option2);
    return memo[i][j];
}

// TC: O(n^2)
// AS: O(n^2)
int getMaxScore(vector<int> coins) {
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (n, -1));
    return getMaxScoreUtil(0, coins.size() - 1, coins, memo);
}

int main() {
    // Problem Statement: https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
    cout << getMaxScore({5, 3, 7, 10}) << endl;
    cout << getMaxScore({8, 15, 3, 7}) << endl;
}
