#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool dfsf(int node,int parent,vector<int> adj[],vector<int>&visited)
    {
        visited[node]=1;

        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                if(dfsf(it,node,adj,visited)) return true;
            }
            else if(parent!=it)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(dfsf(i,-1,adj,visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}