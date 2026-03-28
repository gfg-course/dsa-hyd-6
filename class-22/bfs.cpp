#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// AS: O(V)
vector<int> getDistToAllNodes(vector<vector<int>> adj, int source) {

    int V = adj.size();
    vector<int> dist(V);
    vector<bool> vis(V, false);

    queue<int> q;
    q.push(source);
    vis[source] = true;

    int currentDistance = 0;
    dist[source] = 0;

    while (!q.empty()) {
        int sz = q.size();
        for (int _ = 0; _ < sz; _++) {
            int u = q.front();
            dist[u] = currentDistance;
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        currentDistance++;
    }

    return dist;
}

int main() {

    vector<int> res = getDistToAllNodes({
        {1, 2},
        {0, 6, 4, 3},
        {0, 7, 5},
        {1},
        {1, 7},
        {2},
        {1},
        {2, 4}
    }, 0);

    for (int i = 0; i < res.size(); i++) {
        cout << i << " -> " << res[i] << endl;
    }
}
