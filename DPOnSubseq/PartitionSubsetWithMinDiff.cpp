#include <bits/stdc++.h>
using namespace std;

int minimumDifference(int n, vector<int>& arr) {
    //vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    //return subsetSumUtil(n - 1, k, arr, dp);
    int k=0;
    for(auto it:arr)
    {
      k+=it;
    }

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

    int mini=INT_MAX;
    for(int i=0;i<=k;i++)
    {
      if(prev[i]==true)
      {
        int diff=abs(i-(k-i));
        mini=min(mini,diff);
      }
    }
    return mini;
}

int main() {
    vector<int> arr = {8,6,5};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minimumDifference(n,arr);

    return 0;
}