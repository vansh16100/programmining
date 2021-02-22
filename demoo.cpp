#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
bool found(int arr[],int n,int k,int x) {
  int tmp[n];
  for(int i=0;i<n;i++) {
    if(arr[i]<x) tmp[i] = -1;
    else tmp[i] = 1;
  }
  for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+tmp[i];
  int mx=tmp[k-1];
  int mn=INT_MAX;
  for(int i=k;i<n;i++) {
    mn=min(mn,tmp[i-k]);
    mx=max(max(tmp[i],mx),tmp[i]-mn);
  }
  if(mx>0) return true;
  else return false;
}
int maxMedian(int arr[],int n,int k) {
//return 0;
  int l=1;
  int r=n;
  int ans;
  while(l<=r) {
    int mid = (l+r)/2;
    if(found(arr,n,k,mid)) {
      ans=mid;
      l=mid+1;
    }else {
      r=mid-1;
    }
  }
  return ans;
}
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
