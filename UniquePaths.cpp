#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*int calculate(int m,int n,vector<vector<int>>&dp)
    {
        if(m==0 && n==0)
        {
            return dp[m][n]=1;
        }

        if(m<0 || n<0)
        {
            return 0;
        }

        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        
        int up=calculate(m-1,n,dp);
        int left=calculate(m,n-1,dp);

        return dp[m][n]= up+left;
    }*/

    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        //return calculate(m-1,n-1,dp);

        vector<int> prev(n,-1);

        for(int i=0;i<m;i++)
        {
          vector<int> temp(n,0);
          for(int j=0;j<n;j++)
          {
            if(i==0 && j==0)
            {
              prev[j]=1;
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

int main()
{
    Solution obj;
    
    int m = 3;
    int n = 7;
    
    cout << "Number of unique paths for grid " << m << " x " << n << " is: ";
    cout << obj.uniquePaths(m, n) << endl;
    
    return 0;
}
