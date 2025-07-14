#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*int calculate(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if (j < 0 || j > matrix[0].size() - 1)
        {
            return INT_MAX;
        }
        if (i == 0)
        {
            return dp[i][j] = matrix[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        long long s = matrix[i][j] + (long long)calculate(i - 1, j, matrix, dp);
        long long dl = matrix[i][j] + (long long)calculate(i - 1, j - 1, matrix, dp);
        long long dr = matrix[i][j] + (long long)calculate(i - 1, j + 1, matrix, dp);

        return dp[i][j] = (int)min(s, min(dl, dr));
    }*/

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

       /*vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, calculate(m - 1, i, matrix, dp));
        }
        return ans;*/

        vector<int> prev(n,0);
        for(int i=0;i<n;i++)
        {
          prev[i]=matrix[0][i];
        }

        for(int i=1;i<m;i++)
        {
          vector<int> curr(n,0);
          for(int j=0;j<n;j++)
          {
            int s = matrix[i][j] +prev[j];
            int dl = matrix[i][j];
            if(j>0)
            {
              dl+=prev[j-1];
            }
            else
            {
              dl=INT_MAX;
            }
            
            int dr = matrix[i][j];
            if(j<n-1)
            {
              dr+=prev[j+1]; 
            } 
            else
            {
              dr=INT_MAX;
            }
            
            curr[j]=(int)min(s,min(dl,dr));          
          }
          prev=curr;
        }
        
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
          mini=min(mini,prev[i]);
        }
        return mini;
    }
};

int main() {
    Solution sol;

    // Example test case:
    // Input matrix:
    // [
    //   [2,1,3],
    //   [6,5,4],
    //   [7,8,9]
    // ]
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result = sol.minFallingPathSum(matrix);
    cout << "Minimum falling path sum: " << result << endl;

    return 0;
}
