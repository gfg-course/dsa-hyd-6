#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> buildAdj(int V, vector<vector<int>> &edges) {

    vector<vector<pair<int, int>>> adj(V);

    for (vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return adj;
}

// TC: TODO
// AS: TODO
vector<int> dijikstra(int V, vector<vector<int>> edges, int source) {

    vector<vector<pair<int, int>>> adj = buildAdj(V, edges);

    vector<int> dist(V, INT_MAX);

    // {distU, U}
    priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> pq; // min-heap.


    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty()) {

        pair<int, int> curr = pq.top();
        pq.pop();

        int distU = curr.first;
        int u = curr.second;

        for (pair<int, int> neighbor : adj[u]) {
            int v = neighbor.first;
            int distUV = neighbor.second;

            if (distU + distUV < dist[v]) {
                dist[v] = distU + distUV;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    vector<int> res = dijikstra(9, {
        {0, 1, 4},
        {0, 7, 8},
        {1, 7, 11},
        {1, 2, 8},
        {7, 8, 7},
        {7, 6, 1},
        {2, 8, 2},
        {8, 6, 6},
        {2, 3, 7},
        {2, 5, 4},
        {6, 5, 2},
        {3, 5, 14},
        {3, 4, 9},
        {5, 4, 10}
    }, 0);

    for (int i = 0; i < 9; i++) {
        cout << i << " -> " << res[i] << endl;
    }
}
