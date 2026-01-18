#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &maze) {
    return
        i >= 0 && i < maze.size() &&
        j >= 0 && j < maze[i].size() &&
        maze[i][j] == 1;
}

// DLRU
int dx[4] = {+1, +0, +0, -1};
int dy[4] = {+0, -1, +1, +0};
char dir[4] = {'D', 'L', 'R', 'U'};
void getPathsUtil(int i, int j, vector<vector<int>> &maze, string &curr, vector<string> &result) {
    if (i == maze.size() - 1 && j == maze[i].size() - 1) {
        result.push_back(curr);
        return;
    }

    maze[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (isSafe(new_i, new_j, maze)) {
            curr.push_back(dir[k]);
            getPathsUtil(new_i, new_j, maze, curr, result);
            curr.pop_back();
        }
    }

    // DLRU
    // if (isSafe(i + 1, j, maze)) {
    //     curr.push_back('D');
    //     getPathsUtil(i + 1, j, maze, curr, result);
    //     curr.pop_back();
    // }
    // if (isSafe(i, j - 1, maze)) {
    //     curr.push_back('L');
    //     getPathsUtil(i, j - 1, maze, curr, result);
    //     curr.pop_back();
    // }
    // if (isSafe(i, j + 1, maze)) {
    //     curr.push_back('R');
    //     getPathsUtil(i, j + 1, maze, curr, result);
    //     curr.pop_back();
    // }
    // if (isSafe(i - 1, j, maze)) {
    //     curr.push_back('U');
    //     getPathsUtil(i - 1, j, maze, curr, result);
    //     curr.pop_back();
    // }

    maze[i][j] = 1;
}


// TC: O(4 ^ (n^2))
// AS: O(n^2)
vector<string> getPaths(vector<vector<int>> maze) {
    
    string curr = "";
    vector<string> result;
    getPathsUtil(0, 0, maze, curr, result);

    return result;
}

int main() {

    vector<string> result = getPaths({{1, 0, 0, 0},
                                      {1, 1, 0, 1},
                                      {1, 1, 0, 0},
                                      {0, 1, 1, 1}});

    for (auto i : result) {
        cout << i << " ";
    }
}
