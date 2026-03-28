#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res) {
    vis[u] = true;
    res.push_back(u);

    for (int v : adj[u]) {
        if (!vis[v]) {
            dfsUtil(v, adj, vis, res);
        }
    }
}

// TC: O(V + E)
// AS: O(V)
vector<int> dfs(vector<vector<int>> adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited, result);
        }
    }
    return result;
}

int main() {

    vector<int> res = dfs({
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3},
        {6},
        {5}
    });

    for (int i : res) {
        cout << i << " ";
    }
}
