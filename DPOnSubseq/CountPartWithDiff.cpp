#include <bits/stdc++.h>
using namespace std;

int countPartitions(int n,int diff, vector<int>& arr) {
    int k=0;
    for(auto it:arr)
    {
      k+=it;
    }

    if(k-diff<0 || (k-diff)%2)
    {
      return 0;
    }

    k=(k-diff)/2;

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
    vector<int> arr = {1,1,2,3};
    int n = arr.size();

    int diff=1;

    cout << "The no of partitions is: " << countPartitions(n,diff,arr);

    return 0;
}