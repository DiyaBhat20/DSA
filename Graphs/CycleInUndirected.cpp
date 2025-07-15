#include <bits/stdc++.h>
using namespace std;

bool detect(int node,vector<int> adj[],vector<int>& visited)
{
    visited[node]=1;
    
    queue<pair<int,int>> que;
    que.push({node,-1});

    while(!que.empty())
    {
        int x=que.front().first;
        int parent=que.front().second;
        que.pop();
        for(auto it:adj[x])
        {
            if(visited[it]==0)
            {
                que.push({it,x});
                visited[it]=1;
            }
            else if(parent!=it)
            {
                return true;
            }
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
            if(detect(i,adj,visited)) return true;
        }
    }
    return false;
}

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}