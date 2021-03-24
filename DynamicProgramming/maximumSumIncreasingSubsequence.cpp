#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;


int maximumSumIncreasingSubsequence(int arr[],int n) {
      int dp[n];
    
      for(int i=0;i<n;i++) dp[i]=arr[i];

      if(n==1) return arr[0];

      for(int i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
          if(arr[i] > arr[j]) {
            dp[i]=max(dp[j]+arr[i],dp[i]);
          }
        }
      }
      //return maximum from dp
      int mx=INT_MIN;  //initializing with the minus INF
      for(int i=0;i<n;i++) {
        mx=max(mx,dp[i]);
      }
      return mx;
}

 void solve(){
  // cin>>M>>N;
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  cout<<maximumSumIncreasingSubsequence(arr,n);
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
