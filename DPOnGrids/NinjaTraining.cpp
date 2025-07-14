#include <bits/stdc++.h>
using namespace std;

/*Recursion
int f(int day, int last, vector<vector<int>> &points) {
  if(day==0)
  {
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
      if(last!=i)
      {
        maxi=max(maxi,points[day][i]);
      }
    }
    return maxi;
  }

  int maxi=INT_MIN;
  for(int i=0;i<3;i++)
  {
    if(last!=i)
    {
      int pts=points[day][i]+f(day-1,i,points);
      maxi=max(pts,maxi);
    }
  }
  return maxi;
}*/

/*Memoization
int f(int day, int last,vector<vector<int>>&dp, vector<vector<int>> &points) {
  if(dp[day][last]!=-1)
  {
    return dp[day][last];
  }

  if(day==0)
  {
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
      if(last!=i)
      {
        maxi=max(maxi,points[day][i]);
      }
    }
    return dp[day][last]=maxi;
  }

  int maxi=INT_MIN;
  for(int i=0;i<3;i++)
  {
    if(last!=i)
    {
      int pts=points[day][i]+f(day-1,i,dp,points);
      maxi=max(pts,maxi);
    }
  }
  return dp[day][last]=maxi;
}*/

int ninjaTraining(int n, vector<vector<int>> &points) {
  /*vector<vector<int>> dp(n,vector<int>(4,-1));

  dp[0][0]=max(points[0][1],points[0][2]);
  dp[0][1]=max(points[0][0],points[0][2]);
  dp[0][2]=max(points[0][0],points[0][1]);
  dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));*/

  vector<int> dp(4,-1);

  dp[0]=max(points[0][1],points[0][2]);
  dp[1]=max(points[0][0],points[0][2]);
  dp[2]=max(points[0][0],points[0][1]);
  dp[3]=max(points[0][0],max(points[0][1],points[0][2]));

  for(int day=1;day<n;day++)
  {
    vector<int> temp(4,0);
    for(int last=0;last<4;last++)
    {
      int maxi=INT_MIN;
      for(int i=0;i<3;i++)
      {
        if(last!=i)
        {
          int pts=points[day][i]+dp[i];
          maxi=max(pts,maxi);
        }
      }
      temp[last]=maxi;
    }
    dp=temp;
  }

  return dp[3];

  //return f(n-1,3,dp,points);
  //return f(n-1,3,points);
}

int main()
{
    // Define the points matrix
  vector<vector<int>> points = {{10, 40, 70},
                                 {20, 50, 80},
                                 {30, 60, 90}};

  int n = points.size();  // Get the number of days
  // Call the ninjaTraining function to find the maximum points and print the result
  cout << ninjaTraining(n, points);
  return 0;
}