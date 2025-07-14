#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    /*Recursive
    int recFun(vector<int>& heights, int ind) {
        if (ind == 0) {
            return 0;
        }
        
        int left = recFun(heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        
        int right = INT_MAX;
        if (ind > 1) {
            right = recFun(heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
        }
        
        return min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return recFun(heights, n - 1);
    }*/

    /*Memoization
    int recFun(vector<int>& dp,vector<int>& heights, int ind) {
        if (ind == 0) {
            return dp[0]=0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        int left = recFun(dp,heights, ind - 1) + abs(heights[ind] - heights[ind - 1]);
        
        int right = INT_MAX;
        if (ind > 1) {
            right = recFun(dp,heights, ind - 2) + abs(heights[ind] - heights[ind - 2]);
        }
        
        return dp[ind]=min(left, right);
    }

    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int>dp(n+1,-1);
        return recFun(dp,heights, n - 1);
    }*/

    int frogJump(vector<int>& heights) {
        int n=heights.size();
        vector<int>dp(n+1,-1);
        int prev1=0;
        int prev2=0;
        for(int ind=1;ind<n;ind++)
        {
            int fs=prev1 + abs(heights[ind] - heights[ind - 1]);
            int ss=INT_MAX;
            if(ind>1)
            {
                ss=prev2 + abs(heights[ind] - heights[ind - 2]);
            }
            int curri=min(fs,ss);
            prev2=prev1;
            prev1=curri;
        }
        return prev1;
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
    
    Solution sol;
    int minCost = sol.frogJump(heights);
    cout << "Minimum total cost for the frog: " << minCost << endl;

    return 0;
}
