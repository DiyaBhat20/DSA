#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*int calculate(int m,int n,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp)
    {
        if((m==0 && n==0) && obstacleGrid[m][n]!=1)
        {
            return dp[m][n]=1;
        }

        if(m<0 || n<0 || obstacleGrid[m][n]==1)
        {
            return 0;
        }

        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }

        int up=calculate(m-1,n,obstacleGrid,dp);
        int left=calculate(m,n-1,obstacleGrid,dp);

        return dp[m][n]=up+left;
    }*/

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        //return calculate(m-1,n-1,obstacleGrid,dp);

        vector<int> prev(n,-1);

        for(int i=0;i<m;i++)
        {
          vector<int> temp(n,0);
          for(int j=0;j<n;j++)
          {
            if((i==0 && j==0) && obstacleGrid[i][j]!=1)
            {
              prev[j]=temp[j]=1;
              continue;
            }

            if(obstacleGrid[i][j]==1)
            {
              temp[j]=0;
              continue;
            }

            int up=0,left=0;

            if(i>0)
            {
              up=prev[j];
            }

            if(j>0)
            {
              left=temp[j-1];
            }
            temp[j]=up+left;
          }
          prev=temp;
        }
        return prev[n-1];
    }
};

int main() {
    Solution sol;

    // Example obstacle grid
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}