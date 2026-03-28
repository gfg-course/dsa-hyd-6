#include<bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int dy[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

bool isSafe(int i, int j, int n, vector<vector<bool>> &vis) {
    return
        i >= 1 && i <= n &&
        j >= 1 && j <= n &&
        vis[i][j] == false;
}

// TC: O(n^2)
// AS: O(n^2)
// V = n^2, E ~ 8*n^2
int getMinStepsByKnight(int n, pair<int, int> sourcePos, pair<int, int> targetPos) {

    vector<vector<bool>> vis(n + 1, vector<bool> (n + 1, false));

    queue<pair<int, int>> q;
    q.push(sourcePos);
    vis[sourcePos.first][sourcePos.second] = true;
    int currentDistance = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            pair<int, int> u = q.front();
            q.pop();

            if (u == targetPos) {
                return currentDistance;
            }

            int i = u.first;
            int j = u.second;

            for (int k = 0; k < 8; k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];

                if (isSafe(new_i, new_j, n, vis)) {
                    vis[new_i][new_j] = true;
                    q.push({new_i, new_j});
                }
            }
        }

        currentDistance++;
    }

    return -1;
}

int main() {

    cout << getMinStepsByKnight(6, {4, 5}, {1, 1}) << endl;
}
