#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;


int max(int a,int b,int c) {
  return max(a,max(b,c));
}
int maximumSumNoThreeCon(int arr[],int n) {
  int dp[n+1];
  dp[0]=arr[0];
  dp[1]=arr[0]+arr[1];
  dp[2]=max(dp[1],arr[2]+dp[0],arr[2]+arr[1]);
  for(int i=3;i<n;i++) {
    dp[i]=max(dp[i-1],arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]);
  }
  return dp[n-1];
}
 void solve(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<maximumSumNoThreeCon(arr,n);
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
