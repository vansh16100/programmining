# programmining
dynammicProgramming
#include <bits/stdc++.h>
#include<math.h>
#include<iostream>
#define ll long long int
#define pii pair<int,int>
#define pic pair<int,char>
using namespace std;
using v_i=vector<int>;

int optimalStrategyGame(int arr[],int n) {
  int dp[n+1][n+1];
  for(int l=1;l<=n;l++) {
    int i=1;
    int j=l;

    while(j<=n) {

       if(l==1) dp[i][j]=arr[i-1];
       else if(l==2) dp[i][j]=max(arr[i-1],arr[j-1]);
       else {
           dp[i][j]=max( arr[i-1]+min(dp[i+2][j],dp[i+1][j-1]) , arr[j-1]+min(dp[i+1][j-1],dp[i][j-2]) );
       }
       i++;
       j++;

    }
  }
  return dp[1][n];
}

 void solve(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];

  cout<<optimalStrategyGame(arr,n);
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
