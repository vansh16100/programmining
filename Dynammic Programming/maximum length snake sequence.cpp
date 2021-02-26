#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;
#define M 4
#define N 4

int maximumLengthSnakesequence(int arr[M][N]) {
  int dp[M][N];
  int m=M;
  int n=N;
  for(int i=0;i<n;i++) dp[0][i]=1;
  for(int j=0;j<m;j++) dp[j][0]=1;

  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
        int a,b;
        if(j>0 && ((arr[i][j]==arr[i][j-1]-1) || (arr[i][j]==arr[i][j-1]+1))) a=dp[i][j-1]+1;
        else a=1;
        if(((i)>0) && ((arr[i][j]==arr[i-1][j]-1) || (arr[i][j]==arr[i-1][j]+1))) b=dp[i-1][j]+1;
        else b=1;

        dp[i][j]=max( a , b );
    }
  }
  int mx=INT_MIN;
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) {
      mx=max(mx,dp[i][j]);
    }
  }
  return mx;
}
 void solve(){
  // cin>>M>>N;
   int arr[M][N];
  for(int i=0;i<M;i++) {
    for(int j=0;j<N;j++) {
      cin>>arr[i][j];
    }
  }
  cout<<maximumLengthSnakesequence(arr);
  
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
