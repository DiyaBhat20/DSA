#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfsf(int node,vector<int> adj[],vector<int> visited,vector<int>& dfs)
    {
      visited[node]=1;
      dfs.push_back(node);

      for(auto it:adj[node])
      {
        if(visited[it]==0)
        {
          dfsf(it,adj,visited,dfs);
        }
      }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
     vector<int> visited(V,0);
     vector<int> dfs;

     dfsf(0,adj,visited,dfs);
     return dfs;
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
    vector<int> ans = obj.dfsOfGraph(V, adj);

    for (int node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}