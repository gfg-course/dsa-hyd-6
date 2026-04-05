#include<bits/stdc++.h>
using namespace std;

int inf = 1e6;

int getMinCoinsUtil(int i, vector<int> &coins, int value, vector<vector<int>> &memo) {
    if (value == 0) {
        return 0;
    }
    if (i == coins.size()) {
        return inf;
    }
    if (memo[i][value] != -1) {
        return memo[i][value];
    }

    // skip.
    int result = getMinCoinsUtil(i + 1, coins, value, memo);

    // take it, if possible.
    if (coins[i] <= value) {
        result = min(result, 1 + getMinCoinsUtil(i, coins, value - coins[i], memo));
    }

    return memo[i][value] = result;
}

// Plain Rec:
// TC: O(2^max(n, value))
// AS: O(max(n, value))

// DP:
// TC: O(n*value)
// AS: O(n*value)
int getMinCoins(vector<int> coins, int value) {

    int n = coins.size();
    vector<vector<int>> memo(n, vector<int> (value + 1, -1));

    int result = getMinCoinsUtil(0, coins, value, memo);
    if (result >= inf) {
        return -1;
    }
    return result;
}

int main() {

    cout << getMinCoins({2, 5, 3, 6}, 10) << endl;
    cout << getMinCoins({3, 6}, 10) << endl;
}
