#include <bits/stdc++.h>
using namespace std;

bool canPartition(int n, vector<int>& arr) {
  int tsum = accumulate(arr.begin(), arr.end(), 0);
  if(tsum%2!=0)
  {
    return false;
  }

  int k=tsum/2;
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
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}