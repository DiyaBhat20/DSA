#include <bits/stdc++.h>
using namespace std;

/*int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
  if(j1<0 || j1>=m || j2<0 || j2>=m)
  {
    return INT_MIN;
  }

  if(i==n-1)
  {
    return dp[i][j1][j2]=dp[i][j2][j1]=(j1==j2?grid[i][j1]:grid[i][j1]+grid[i][j2]);
  }

  if(dp[i][j1][j2]!=-1)
  {
    return dp[i][j1][j2];
  }

  int maxi=INT_MIN;
  for(int di=-1;di<=1;di++)
  {
    for(int dj=-1;dj<=1;dj++)
    {
      int ans;
      if(j1==j2)
      {
        ans=grid[i][j1]+maxChocoUtil(i+1,j1+di,j2+dj,n,m,grid,dp);
      }
      else
      {
        ans=grid[i][j1]+grid[i][j2]+maxChocoUtil(i+1,j1+di,j2+dj,n,m,grid,dp);
      }
      maxi=max(maxi,ans);
    }
  }
  return dp[i][j1][j2]=maxi;
}*/

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    //vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    //return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
  vector<vector<int>>front(m,vector<int>(m,0));
  for(int j1=0;j1<m;j1++)
  {
    for(int j2=0;j2<m;j2++)
    {
      if(j1==j2)
      {
        front[j1][j2]=grid[n-1][j1];
      }
      else
      {
        front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
      }
    }
  }

  for(int i=n-2;i>=0;i--)
  {
    vector<vector<int>>cur(m,vector<int>(m,0));
    for(int j1=0;j1<m;j1++)
    {
      for(int j2=0;j2<m;j2++)
      {
        int maxi=INT_MIN;

        for(int di=-1;di<=1;di++)
        {
          for(int dj=-1;dj<=1;dj++)
          {
            int ans;
            if(j1==j2)
            {
              ans=grid[i][j1];
            }
            else
            {
              ans=grid[i][j1]+grid[i][j2];
            }

            if(j1+di<0 || j1+di>=m || j2+dj<0 || j2+dj>=m)
            {
              ans+=INT_MIN;
            }
            else
            {
              ans+=front[j1+di][j2+dj];
            }

            maxi=max(maxi,ans);
          }
        }
        cur[j1][j2]=maxi;
      }
    }
    front=cur;
  }

  return front[0][m-1];
}

int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}