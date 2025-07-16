#include <bits/stdc++.h>
using namespace std;

/*int f(int ind,int t,vector<int>& coins)
{
  if(ind==0)
  {
    if(t%coins[0]==0)
    {
      return t/coins[0];
    }
    else
    {
      return INT_MAX;
    }
  }

  int ntake=0+f(ind-1,t,coins);

  int take=INT_MAX;
  if(coins[ind]<=t)
  {
    take=1+f(ind,t-coins[ind],coins);
  }
  return min(take,ntake);
}*/

int coinChange(vector<int>& coins, int amount) {
    //int ans=f(coins.size()-1,amount,coins);
    //return ans>=INT_MAX?-1:ans;

    int n=coins.size();

    //vector<vector<int>> dp(n,vector<int>(amount+1,-1));

    vector<int> prev(amount+1,0);

    for(int i=0;i<=amount;i++)
    {
      //dp[0][i]=(i%coins[0]==0?i/coins[0]:1e9);
      prev[i]=(i%coins[0]==0?i/coins[0]:1e9);
    }

    for(int i=1;i<n;i++)
    {
      vector<int> cur(amount+1,0);
      for(int t=0;t<=amount;t++)
      {
        int ntake=0+prev[t];

        int take=1e9;
        if(coins[i]<=t)
        {
          take=1+cur[t-coins[i]];
        }
        cur[t]= min(take,ntake);        
      }
      prev=cur;
    }

    //return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];
    return prev[amount]>=1e9?-1:prev[amount];
}

int main() {

    vector<int> arr = {1, 2, 3};
    int T = 7;
                                 
    cout << "The minimum number of coins required to form the target sum is " << coinChange(arr, T);

    return 0; // Return 0 to indicate successful program execution
}
