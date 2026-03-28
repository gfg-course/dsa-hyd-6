#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-1, +1, +0, +0, -1, -1, +1, +1};
int dy[8] = {+0, +0, -1, +1, -1, +1, -1, +1};

bool isSafe(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &vis) {
    return 
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1 && !vis[i][j];
}

void dfsUtil(int i, int j, vector<vector<int>> &arr, vector<vector<bool>> &vis) {
    vis[i][j] = true;

    for (int k = 0; k < 8; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if (isSafe(new_i, new_j, arr, vis)) {
            dfsUtil(new_i, new_j, arr, vis);
        }
    }
}

// TC: O(nm)
// AS: O(nm)
// Its a DFS with V = nm and E ~ 8*nm
int countIslands(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<bool>> vis(n, vector<bool> (m, false));

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && arr[i][j] == 1) {
                count++;
                dfsUtil(i, j, arr, vis);
            }
        }
    }

    return count;
}

int main() {

    cout << countIslands({
        {0, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 0}
    }) << endl;
}
