#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*int calculate(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1)
        {
            return triangle[i][j];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int d = triangle[i][j] + calculate(i+1, j, triangle, dp);
        int dg = triangle[i][j] + calculate(i+1, j+1, triangle, dp);

        return dp[i][j] = min(d, dg);
    }*/

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        /*vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++) {
            dp[i] = vector<int>(i+1, -1);
        }*/

        //return calculate(0, 0, triangle, dp);

        vector<int> front(triangle[m-1].size(),0);
        for(int i=0;i<triangle[m-1].size();i++)
        {
          front[i]=triangle[m-1][i];
        }

        for(int i=m-2;i>=0;i--)
        {
          vector<int> cur(i+1, 0);
          for(int j=i;j>=0;j--)
          {
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j+1];
            cur[j]=min(d,dg);
          }  
          front=cur;
        }
        return front[0];
    }
};

int main() {
    Solution sol;

    // Example triangle:
    // [
    //      [2],
    //     [3,4],
    //    [6,5,7],
    //   [4,1,8,3]
    // ]
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    int result = sol.minimumTotal(triangle);
    cout << "Minimum path sum: " << result << endl;

    return 0;
}
