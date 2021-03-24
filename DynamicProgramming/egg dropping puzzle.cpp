//https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int eggDropping(int e,int f) {
  int dp[e+1][f+1];
  for(int i=0;i<=f;i++) dp[0][i]=0,dp[1][i]=i;
  for(int i=0;i<=e;i++) dp[i][0]=0,dp[i][1]=1;

  for(int i=2;i<=e;i++) {
    for(int j=2;j<=f;j++) {
      int mi=INT_MAX;
      for(int x=1;x<=j;x++) {
        int res = max(dp[i][x-1],dp[i-1][j-x]);
        mi=min(res,mi);
      }
      dp[i][j]=mi+1;
    }
  }
  return dp[e][f];
}
 void solve(){
  int e,f;
  cin>>e>>f;
 
  cout<<eggDropping(e,f)<<"\n";
}


int main() {
   // your code goes here
    // int t;
    // cin>>t;
    // while(t--){
        solve();
  // }
    return 0;
}
