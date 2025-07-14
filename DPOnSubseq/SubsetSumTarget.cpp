#include <bits/stdc++.h>
using namespace std;

/*bool subsetSumUtil(int ind,int target,vector<int>& arr,vector<vector<int>> &dp)
{
  if(target==0)
  {
    return true;
  }

  if(dp[ind][target]!=-1)
  {
    return dp[ind][target];
  }

  if(ind==0)
  {
    return dp[ind][target]=(arr[0]==target);
  }

  bool take=false;
  if(arr[ind]<=target)
  {
    take=subsetSumUtil(ind-1,target-arr[ind],arr,dp);
  }
  bool ntake=0+subsetSumUtil(ind-1,target,arr,dp);

  return dp[ind][target]=take || ntake;
}*/

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int>& arr) {
    //vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    //return subsetSumUtil(n - 1, k, arr, dp);

    vector<bool>prev(k+1,false);
    prev[0]=true;

    if(arr[0]<=k)
    {
      prev[arr[0]]=true;
    }

    for(int ind=1;ind<n;ind++)
    {
      vector<bool>cur(k+1,false);
      cur[0]=true;
      for(int target=1;target<=k;target++)
      {
        bool take=false;
        if(arr[ind]<=target)
        {
          take=prev[target-arr[ind]];
        }
        bool ntake=prev[target];
        cur[target]=take || ntake;
      }
      prev=cur;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}