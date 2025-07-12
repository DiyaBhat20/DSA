#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   /* int recFun(int ind,vector<int>&nums)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;

        int pick=nums[ind]+recFun(ind-2,nums);
        int notpick=0+recFun(ind-1,nums);

        return max(pick,notpick);
    }
    */
   /* int recFun(int ind,vector<int>&nums,vector<int>& dp)
    {
        if(ind==0) return dp[ind]=nums[ind];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+recFun(ind-2,nums,dp);
        int notpick=0+recFun(ind-1,nums,dp);

        return dp[ind]=max(pick,notpick);
    }
    */
    int rob(vector<int>& nums) {
        int n=nums.size();
        //vector<int> dp(n,-1);
        //dp[0]=nums[0];
        int prev1=nums[0];
        int prev2=0;
        for(int ind=1;ind<n;ind++)
        {
            int pick=nums[ind];
            if(ind>1)
            {
                pick+=prev2;//dp[ind-2];
            }
            int notpick=0+prev1;//dp[ind-1];
            //dp[ind]
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;            
        }
        return prev1;//dp[n-1];
        //return recFun(n-1,nums,dp);
    }
};

int main() {
    Solution sol;
    
    int n;
    cout << "Enter number of houses: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter amount of money in each house:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    int result = sol.rob(nums);
    
    cout << "Maximum amount that can be robbed: " << result << endl;
    
    return 0;
}