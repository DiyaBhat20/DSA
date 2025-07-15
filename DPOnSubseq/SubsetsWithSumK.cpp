#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int>&arr, int k){
    int n=arr.size();
    vector<int>prev(k+1,0);
    prev[0]=1;

    if(arr[0]<=k)
    {
      prev[arr[0]]=1;
    }

    for(int ind=1;ind<n;ind++)
    {
      vector<int>cur(k+1,0);
      cur[0]=1;
      for(int target=1;target<=k;target++)
      {
        int take=0;
        if(arr[ind]<=target)
        {
          take=prev[target-arr[ind]];
        }
        int ntake=prev[target];
        cur[target]=take + ntake;
      }
      prev=cur;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {2, 3, 5, 16, 8, 10};
    int k = 10;

    cout << "The number of subsets found are " << findWays(arr, k);

    return 0;
}