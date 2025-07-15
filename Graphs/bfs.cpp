#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        queue<int> que;
        vector<int> bfs;

        que.push(0);
        visited[0] = 1;

        while (!que.empty()) {
            int t = que.front();
            bfs.push_back(t);
            que.pop();

            for (auto it : adj[t]) {
                if (visited[it] == 0) 
                {
                    que.push(it);
                    visited[it] = 1;
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V, E;
    cin >> V>>E;
    
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        // Assuming undirected graph:
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> ans = obj.bfsOfGraph(V, adj);

    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
