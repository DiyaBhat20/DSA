  #include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfsOfGraph(int start, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> que;
        que.push(start);
        visited[start] = 1;

        while (!que.empty()) {
            int t = que.front();
            que.pop();

            for (auto it : adj[t]) {
                if (visited[it] == 0) {
                    que.push(it);
                    visited[it] = 1;
                }
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        // Create adjacency list
        vector<vector<int>> adj(V);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                count++;
                bfsOfGraph(i, adj, visited);
            }
        }

        return count;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    int numComponents = obj.findNumberOfComponent(V, edges);
    cout <<"\nComponents : " <<numComponents << endl;

    return 0;
}
