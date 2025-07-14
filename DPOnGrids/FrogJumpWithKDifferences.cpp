#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    /*Recursive
    int recFun(vector<int>& heights, int ind,int k) {
        if (ind == 0) {
            return 0;
        }
        
        int mmsteps = INT_MAX;
        for(int j=1;j<=k;j++) {
            if(ind-j>=0)
            {
              int jump = recFun(heights, ind - j,k) + abs(heights[ind] - heights[ind - j]);
              mmsteps=min(jump,mmsteps);
            }
        }
        
        return mmsteps;
    }

    int frogJump(vector<int>& heights,int k) {
        int n = heights.size();
        return recFun(heights, n - 1,k);
    }*/

    /*Memoization
    int recFun(vector<int>& dp,vector<int>& heights, int ind,int k) {
        if (ind == 0) {
            return dp[0]=0;
        }

        if(dp[ind]!=-1)
        {
          return dp[ind];
        }
        
        int mmsteps = INT_MAX;
        for(int j=1;j<=k;j++) {
            if(ind-j>=0)
            {
              int jump = recFun(dp,heights, ind - j,k) + abs(heights[ind] - heights[ind - j]);
              mmsteps=min(jump,mmsteps);
            }
        }
        
        return dp[ind]=mmsteps;
    }

    int frogJump(vector<int>& heights,int k) {
        int n = heights.size();
        vector<int>dp(n+1,-1);
        return recFun(dp,heights, n - 1,k);
    }*/

    int frogJump(vector<int>& heights,int k) {
        int n=heights.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int ind=1;ind<n;ind++)
        {
          int mmsteps=INT_MAX;
          for(int j=1;j<=k;j++)
          {
            if(ind-j>=0)
            {
                int jump=dp[ind-j] + abs(heights[ind] - heights[ind - j]);
                mmsteps=min(jump,mmsteps);
            }
          }
          dp[ind]=mmsteps;
        }
        return dp[n-1];
    }

};

int main() {
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    
    vector<int> heights(n);
    cout << "Enter the heights of the stones:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int k;
    cout<<"Enter k : ";
    cin>>k;
    
    Solution sol;
    int minCost = sol.frogJump(heights,k);
    cout << "Minimum total cost for the frog: " << minCost << endl;

    return 0;
}
